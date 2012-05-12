
package Interface;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javax.swing.JPanel;
import org.jdom.JDOMException;
import javax.swing.JLabel;
import javax.swing.JToolBar;
import javax.swing.JDialog;
import Graph.edge.*;
import Graph.*;
import javax.swing.JOptionPane;

class MainPanel extends JPanel implements InfoListener {

    /** Внутренний радиус круга города */
    private static final int CITY_INT_RADIUS = 6;
    /** Внешний радиус круга города */
    private static final int CITY_EXT_RADIUS = 20;

    /** Мир */
    private graph world;
    /** Слушатель изменения текущего объекта */
    private CurrentListener currentListener;
    /** Текущий город (null - нет) */
    private vertice currentCity;
    /** Текущий путь (null - нет) */
    private edge currentWay;

    /** Режим работы */
    private enum Mode {
        SELECT,       // Выбор
        ADDCITY,      // Добавить город
        ADDWAY_START, // Добавить первую точку пути
        ADDWAY_FINISH, // Добавить вторую точку пути
        SEL_START, //Выбор начальной точки
        SEL_FINISH //Выбор конечной точки
    };

    private Mode mode;
    /** Первая точка пути */
    private vertice startCity;
    /** Слушатель мыши */
    private MouseListener mouseListener;

    /** Инициализация слушателей */
    private void initListeners() {
        mouseListener = new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                onPress(e);
            }
        };
        addMouseListener(mouseListener);
    }

    /**
     * Нажатие мыши в режиме добавления города
     */
    private void onPressAddCity(int x, int y) {
        vertice city = new vertice("Город", x, y);
        world.addVertice(city);
        currentCity = city;
        currentListener.currentCityChanged(city);
        repaint();
    }

    /**
     * Нажатие мыши в режиме добавления пути (первая точка)
     */
    private void onPressAddWayStart(int x, int y) {
        startCity = world.getNearestPoint(x, y);
        if (startCity != null &&
            startCity.getDistanceSquare(x, y) <= CITY_EXT_RADIUS*CITY_EXT_RADIUS) {
            currentCity = startCity;
            currentListener.currentCityChanged(startCity);
            mode = Mode.ADDWAY_FINISH;
            repaint();
        }
    }
    private void onPressAddPointStart(int x, int y)
    {
        startCity = world.getNearestPoint(x, y);
        if (startCity != null &&
            startCity.getDistanceSquare(x, y) <= CITY_EXT_RADIUS*CITY_EXT_RADIUS) {
            currentCity = startCity;
            currentListener.currentCityChanged(startCity);
            mode = Mode.SEL_FINISH;
            repaint();
        }
    }

    /**
     * Нажатие мыши в режиме добавления пути (вторая точка)
     */
    private void onPressAddWayFinish(int x, int y) {
        vertice finishCity = world.getNearestPoint(x, y);
        if (finishCity != null && finishCity != startCity &&
            finishCity.getDistanceSquare(x, y) <= CITY_EXT_RADIUS*CITY_EXT_RADIUS) {
            EdgeKind newWayKind = null;
            // Выбор свободного типа пути
            for (EdgeKind kind: EdgeKind.values()) {
                if (world.getWayByCities(startCity, finishCity, kind)==null) {
                    newWayKind = kind;
                    break;
                }
            }
            // Если свободный тип найден
            if (newWayKind != null) {
                edge newWay = new edge(startCity, finishCity, newWayKind,
                        1000);
                world.addEdge(newWay);
                currentCity = finishCity;
                currentListener.currentCityChanged(finishCity);
                currentWay = newWay;
                currentListener.currentWayChanged(newWay);
                repaint();
                mode = Mode.ADDWAY_START;
            }
        }
    }
    private void onPressAddPointFinish(int x, int y)
    {
        vertice finishCity = world.getNearestPoint(x, y);
        if (finishCity != null && finishCity != startCity &&
            finishCity.getDistanceSquare(x, y) <= CITY_EXT_RADIUS*CITY_EXT_RADIUS) {
            EdgeKind newWayKind = null;
            // Выбор свободного типа пути
            for (EdgeKind kind: EdgeKind.values()) {
                if (world.getWayByCities(startCity, finishCity, kind)==null) {
                    newWayKind = kind;
                    break;
                }
            }
            
            // Если свободный тип найден
            if (newWayKind != null) {
                //edge newWay = new edge(startCity, finishCity, newWayKind,
                        //0);
                //world.addEdge(newWay);
                
                int minpath = world.minpath(world, startCity, finishCity);
                JOptionPane.showMessageDialog(this, String.valueOf(minpath), "Минимальный путь", JOptionPane.INFORMATION_MESSAGE);
                currentCity = finishCity;
                currentListener.currentCityChanged(finishCity);
                //currentWay = newWay;
                //currentListener.currentWayChanged(newWay);
                repaint();
                mode = Mode.SEL_START;
            }
        }
    }
    

    /**
     * Нажатие мыши в режиме выбора
     */
    private void onPressSelect(int x, int y) {
        vertice city = world.getNearestPoint(x, y);
        if (city != null &&
            city.getDistanceSquare(x, y) <= CITY_EXT_RADIUS*CITY_EXT_RADIUS) {
            // Если удалось выбрать город
            currentCity = city;
            currentListener.currentCityChanged(city);
            repaint();
        } else {
            // Если нет - пытаемся выбрать путь
            final edge way = world.getWayByCoord(x, y);
            if (way != null) {
                currentWay = way;
                currentListener.currentWayChanged(way);
                repaint();
            }
        }
    }

    /**
     * Нажатие мыши в режиме удаления (правая кнопка)
     */
    private void onPressRemove(int x, int y) {
        vertice city = world.getNearestPoint(x, y);
        if (city != null &&
            city.getDistanceSquare(x, y) <= CITY_EXT_RADIUS*CITY_EXT_RADIUS) {
            // Удаление города и связанных путей
            world.removeVertice(city);
            if (currentCity==city) {
                currentCity = null;
                currentListener.currentCityChanged(null);
            }
            // Если удален текущий путь ...
            if (currentWay != null && 
                (currentWay.getVert1()==city || currentWay.getVert2()==city)) {
                currentWay = null;
                currentListener.currentWayChanged(null);
            }
        } else {
            // Удаление путей
            edge way = null;
            way = world.getWayByCoord(x, y);
            if (way != null) {
                world.removeEdge(way);
                if (currentWay==way) {
                    currentWay = null;
                    currentListener.currentWayChanged(null);
                }
            }
        }
        repaint();
    }

    /**
     * Обработчик нажатия на клавишу мыши
     */
    private void onPress(MouseEvent e) {
        // Вызывается один из более мелких обработчиков,
        // в зависимости от режима и нажатой клавиши
        if (e.getButton() == MouseEvent.BUTTON1) {
            if (mode==Mode.ADDCITY) {
                onPressAddCity(e.getX(), e.getY());
            } else if (mode==Mode.ADDWAY_START) {
                onPressAddWayStart(e.getX(), e.getY());
            } else if (mode==Mode.ADDWAY_FINISH) {
                onPressAddWayFinish(e.getX(), e.getY());
            } else if(mode == Mode.SEL_START) 
            {
                onPressAddPointStart(e.getX(), e.getY());
            } else if(mode == Mode.SEL_FINISH)
            {
                onPressAddPointFinish(e.getX(), e.getY());
            }
            else {
                onPressSelect(e.getX(), e.getY());
            }
        } else if (e.getButton() == MouseEvent.BUTTON3) {
            if (mode==Mode.SELECT)
                onPressRemove(e.getX(), e.getY());
        }
    }

    /**
     * Конструктор
     */
    public MainPanel(CurrentListener listener) {
        super();
        currentListener = listener;
        world = new graph();
        mode = Mode.SELECT;
        initListeners();
    }

    /**
     * Переустановка слушателя
     */
    public void setListener(CurrentListener listener) {
        currentListener = listener;
        currentListener.currentCityChanged(currentCity);
        currentListener.currentWayChanged(currentWay);
    }

    /**
     * Добавление города
     */
    public void addCity(vertice city) {
        world.addVertice(city);
        repaint();
    }

    /**
     * Добавление пути
     */
    public void addWay(edge way) {
        world.addEdge(way);
        repaint();
    }

    /**
     * Режим добавления города
     */
    public void chooseCityMode() {
        mode = Mode.ADDCITY;
    }
    
    /**
     * Режим добавления пути
     */
    public void chooseWayMode() {
        mode = Mode.ADDWAY_START;
    }
    
    public void chooseSelMode()
    {
        mode = Mode.SEL_START;
    }

    /**
     * Режим выбора
     */
    public void chooseSelectMode() {
        mode = Mode.SELECT;
    }

    /**
     * Прочитать мир из заданного файла
     */
    public void openWorldFromFile(File file) throws IOException, ClassNotFoundException {
        ObjectInputStream inputStream = new ObjectInputStream(
                new FileInputStream(file));
        world = (graph)inputStream.readObject();
        inputStream.close();
    }

    /**
     * Прочитать мир из заданного XML-файла
     */
    public void openWorldFromXML(File file) throws IOException, JDOMException {
        world.readXML(file);
    }

    /**
     * Сохранить мир в заданный файл
     */
    public void saveWorldToFile(File file) throws IOException {
        ObjectOutputStream outputStream = new ObjectOutputStream(
                new FileOutputStream(file));
        outputStream.writeObject(world);
        outputStream.close();
    }

    /**
     * Сохранить мир в заданном XML-файле
     */
    public void saveWorldToXML(File file) throws IOException {
        world.writeXML(file);
    }

    /**
     * Обработчик изменения имени города
     */
    public void cityNameChanged(String name) {
        if (currentCity != null) {
            currentCity.setName(name);
            repaint();
        }
    }

    /**
     * Обработчик изменения типа пути
     */
    public void wayKindChanged(EdgeKind kind) {
        if (currentWay != null) {
            edge newWay = world.getWayByCities(currentWay.getVert1(),
                    currentWay.getVert2(), kind);
            // Выбрать уже существующий путь такого типа
            if (newWay != null) {
                currentWay = newWay;
                currentListener.currentWayChanged(newWay);
            } else {
                // Или изменить тип выбранного пути
                currentWay.setKind(kind);
            }
            repaint();
        }
    }

    /**
     * Обработчик изменения стоимости пути
     */
    public void wayCostChanged(int cost) {
        if (currentWay != null)
            currentWay.setDistance(cost);
    }

    /**
     * Обработчик изменения времени в пути
     */
    public void wayTimeChanged(int time) {
        if (currentWay != null)
            currentWay.setFlag(time);
    }

    /**
     * Получение мира
     */
    public graph getWorld() {
        return world;
    }

    /**
     * Рисуем заданный город
     */
    private void paintCity(Graphics g, vertice city) {
        /*g.setColor(Color.RED);
        g.fillOval(
                city.getX()-CITY_EXT_RADIUS,
                city.getY()-CITY_EXT_RADIUS,
                2*CITY_EXT_RADIUS, 2*CITY_EXT_RADIUS);*/
        if (city==currentCity) {
            g.setColor(Color.YELLOW);
            g.drawOval(
                    city.getX()-CITY_EXT_RADIUS,
                    city.getY()-CITY_EXT_RADIUS,
                    2*CITY_EXT_RADIUS, 2*CITY_EXT_RADIUS);
        }
        g.setColor(Color.WHITE);
        g.fillOval(
                city.getX()-CITY_EXT_RADIUS,
                city.getY()-CITY_EXT_RADIUS,
                2*CITY_EXT_RADIUS, 2*CITY_EXT_RADIUS);
        g.drawString(city.getName(), city.getX()+CITY_EXT_RADIUS, city.getY());
    }

    /**
     * Рисуем заданный путь
     */
    private void paintWay(Graphics g, edge way) {
        int dx = 0, dy = 0;
        String dist;
        dist = String.valueOf(way.getDistance());
        final vertice start = way.getVert1();
        final vertice finish = way.getVert2();
        if (Math.abs(finish.getX()-start.getX()) >=
            Math.abs(finish.getY()-start.getY())) {
            dy = 1;
        } else {
            dx = 1;
        }
        switch(way.getEdgeKind()) {
            case ORIENTED:
                g.setColor(way==currentWay ? Color.YELLOW : Color.RED);
                g.drawLine(start.getX()+dx, start.getY()+dy,
                        finish.getX()+dx, finish.getY()+dy);
                g.drawString(dist, (start.getX()+dx+finish.getX()+dx)/2, (start.getY() + dy + finish.getY() + dy)/2);
                break;
            case NOTORIENTED:
                g.setColor(way==currentWay ? Color.YELLOW : Color.LIGHT_GRAY);
                g.drawLine(start.getX(), start.getY(),
                        finish.getX(), finish.getY());
                g.drawString(dist, (start.getX()+dx+finish.getX()+dx)/2, (start.getY() + dy + finish.getY() + dy)/2);
                break;
        }
        return;
    }

    /**
     * Обработчик перерисовки
     */
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        for (vertice city: world.getVertice())
            paintCity(g, city);
        for (edge way: world.getEdges())
            paintWay(g, way);
    }
}
