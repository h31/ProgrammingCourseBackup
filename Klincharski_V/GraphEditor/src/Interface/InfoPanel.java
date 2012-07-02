

package Interface;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.BoxLayout;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import Graph.edge.*;
import Graph.*;
import Graph.graph.*;

public class InfoPanel extends JPanel implements CurrentListener {
    /** Метка */
    JLabel cityLabel;
    /** Текстовое поле */
    JTextField cityName;
    JLabel kindLabel;
    /** Список выбора */
    JComboBox wayKind;
    JLabel costLabel;
    /** Счетчик */
    JSpinner wayCost;
    JLabel timeLabel;
    JSpinner wayTime;

    /** Слушатель изменения атрибутов */
    InfoListener infoListener;

    /** Инициализация слушателей всех событий */
    private void initListeners() {
        // Изменение имени города
        cityName.addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent e) {
                if (infoListener != null)
                    infoListener.cityNameChanged(cityName.getText());
            }
        });
        // Изменение типа пути
        wayKind.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (infoListener != null)
                    infoListener.wayKindChanged(getWayKind());
            }
        });
        // Изменение стоимости пути
        wayCost.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                if (infoListener != null)
                    infoListener.wayCostChanged((Integer)wayCost.getValue());
            }
        });
        // Изменение времени в пути
        wayTime.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                if (infoListener != null)
                    infoListener.wayTimeChanged((Integer)wayTime.getValue());
            }
        });
    }

 
    public InfoPanel(InfoListener listener) {
        super();
        // Выбор размещения в одну колонку
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        // Создание и добавление компонентов
        cityLabel = new JLabel("Название узла");
        add(cityLabel);
        cityName = new JTextField(15);
        cityName.setMaximumSize(new Dimension(300, 25));
        add(cityName);
        kindLabel = new JLabel("Вид дуги");
        add(kindLabel);
        String[] kindNames = { 
            EdgeKind.ORIENTED.toString(),
            EdgeKind.NOTORIENTED.toString()
        };
        wayKind = new JComboBox(kindNames);
        wayKind.setMaximumSize(new Dimension(300, 25));
        add(wayKind);
        costLabel = new JLabel("Длина дуги");
        add(costLabel);
        wayCost = new JSpinner(new SpinnerNumberModel(1000, 100, 10000, 100));
        wayCost.setMaximumSize(new Dimension(300, 25));
        add(wayCost);
        timeLabel = new JLabel("Доп информация");
        add(timeLabel);
        wayTime = new JSpinner(new SpinnerNumberModel(1, 0, 20, 1));
        wayTime.setMaximumSize(new Dimension(300, 25));
        add(wayTime);
        this.infoListener = listener;
        initListeners();
    }

    /**
     * Переустановка слушателя
     */
    public void setListener(InfoListener listener) {
        infoListener = listener;
    }

    /**
     * Получение имени города
     */
    public String getCityName() {
        return cityName.getText();
    }

    /**
     * Установка имени города
     */
    public void setCityName(String name) {
        cityName.setEnabled(true);
        
        //if(CheckNameExist(name) != false)
        cityName.setText(name);
    }

    /**
     * Получение типа пути
     */
    public EdgeKind getWayKind() {
        switch (wayKind.getSelectedIndex()) {
            case 0:
                return EdgeKind.ORIENTED;
            default:
                return EdgeKind.NOTORIENTED;
        }
    }

    /**
     * Установка типа пути
     */
    public void setWayKind(EdgeKind kind) {
        wayKind.setEnabled(true);
        switch (kind) {
            case ORIENTED:
                wayKind.setSelectedIndex(0);
                break;
            case NOTORIENTED:
                wayKind.setSelectedIndex(1);
                break;
        }
    }

    /**
     * Получение стоимости пути
     */
    public int getWayCost() {
        return (Integer)(wayCost.getValue());
    }

    /**
     * Установка стоимости пути
     */
    public void setWayCost(int cost) {
        wayCost.setEnabled(true);
        wayCost.setValue(Integer.valueOf(cost));
    }

    /**
     * Получение времени в пути
     */
    public int getWayTime() {
        return (Integer)(wayTime.getValue());
    }

    /**
     * Установка времени в пути
     */
    public void setWayTime(int time) {
        wayTime.setEnabled(true);
        wayTime.setValue(Integer.valueOf(time));
    }

    /**
     * Обработчик выбора текущего города
     */
    public void currentCityChanged(vertice city) {
        if (city==null) {
            cityName.setEnabled(false);
        } else {
            this.setCityName(city.getName());
        }
    }

    /**
     * Обработчик выбора текущего пути
     */
    public void currentWayChanged(edge way) {
        if (way==null) {
            wayKind.setEnabled(false);
            wayCost.setEnabled(false);
            wayTime.setEnabled(false);
        } else {
            this.setWayKind(way.getEdgeKind());
            this.setWayCost(way.getDistance());
            this.setWayTime(way.getFlag());
        }
    }
}
