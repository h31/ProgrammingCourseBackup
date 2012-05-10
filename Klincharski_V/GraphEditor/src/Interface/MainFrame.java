/*
 * MainFrame.java
 */

package Interface;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JToolBar;
import javax.swing.border.BevelBorder;
import javax.swing.filechooser.FileFilter;
import org.jdom.JDOMException;


public class MainFrame extends JFrame {
    /** Текущий файл */
    File currentFile;
    /** Компоненты-дети */
    MainPanel mainPanel;
    InfoPanel infoPanel;
    JPanel statusBar;
    JLabel statusLabel;
    JMenuBar menuBar;
    JMenu fileMenu, modeMenu, viewMenu, infoMenu, operationMenu;
    JMenuItem openMenu, saveMenu, quitMenu, optimiserMenu;
    JRadioButtonMenuItem addCityMenu, addWayMenu, selectMenu;
    JCheckBoxMenuItem fullScreenMenu;
    JMenuItem waysMenu;
    ButtonGroup modeGroup;
    JToolBar toolbar;
    JButton openButton, saveButton, quitButton, verticeButton, edgeButton, cursorButton;
    /** Слушатели */
    ActionListener addCityListener, addWayListener, selectListener;
    ActionListener openListener, saveListener, quitListener;
    ActionListener waysListener;
    ActionListener selListener;
    ItemListener fullScreenListener;

    /**
     * Инициализация информационной панели
     */
    private void initInfoPanel() {
        infoPanel = new InfoPanel(null);
        infoPanel.setPreferredSize(new Dimension(200, 500));
        infoPanel.setMinimumSize(new Dimension(150, 500));
        infoPanel.setBorder(new BevelBorder(BevelBorder.RAISED));
    }

    /**
     * Инициализация панели статуса
     */
    private void initStatusBar() {
        statusBar = new JPanel();
        statusBar.setPreferredSize(new Dimension(500, 25));
        statusBar.setBorder(new BevelBorder(BevelBorder.LOWERED));
        statusBar.setLayout(new FlowLayout(FlowLayout.LEFT));
        statusLabel = new JLabel("Режим выбора");
        statusBar.add(statusLabel);
        this.add(statusBar, BorderLayout.SOUTH);
    }

    /**
     * Инициализация главной панели
     */
    private void initMainPanel() {
        mainPanel = new MainPanel(infoPanel);
        mainPanel.setBackground(new Color(0, 0, 64));
        mainPanel.setPreferredSize(new Dimension(1000, 1000));
        mainPanel.setBorder(new BevelBorder(BevelBorder.LOWERED));
    }

    /**
     * Инициализация меню
     */
    private void initMenuBar() {
        menuBar = new JMenuBar();
        this.setJMenuBar(menuBar);
        fileMenu = new JMenu("Файл");
        menuBar.add(fileMenu);
        openMenu = new JMenuItem("Открыть");
        openMenu.addActionListener(openListener);
        fileMenu.add(openMenu);
        saveMenu = new JMenuItem("Сохранить");
        saveMenu.addActionListener(saveListener);
        fileMenu.add(saveMenu);
        fileMenu.addSeparator();
        quitMenu = new JMenuItem("Выйти");
        quitMenu.addActionListener(quitListener);
        fileMenu.add(quitMenu);
        operationMenu = new JMenu("Операции");
        menuBar.add(operationMenu);
        optimiserMenu = new JMenuItem("Оптимизация пути");
        optimiserMenu.addActionListener(selListener);
        operationMenu.add(optimiserMenu);
        
        /*modeMenu = new JMenu("Режим");
        modeGroup = new ButtonGroup();
        selectMenu = new JRadioButtonMenuItem("Выбор");
        selectMenu.setSelected(true);
        selectMenu.addActionListener(selectListener);
        modeMenu.add(selectMenu);
        modeGroup.add(selectMenu);
        addCityMenu = new JRadioButtonMenuItem("Добавить город");
        addCityMenu.addActionListener(addCityListener);
        modeMenu.add(addCityMenu);
        modeGroup.add(addCityMenu);
        addWayMenu = new JRadioButtonMenuItem("Добавить путь");
        addWayMenu.addActionListener(addWayListener);
        modeMenu.add(addWayMenu);
        modeGroup.add(addWayMenu);
        menuBar.add(modeMenu);
        viewMenu = new JMenu("Вид");
        fullScreenMenu = new JCheckBoxMenuItem("Полноэкранный режим");
        fullScreenMenu.addItemListener(fullScreenListener);
        viewMenu.add(fullScreenMenu);
        menuBar.add(viewMenu);
        * *
        */
        infoMenu = new JMenu("Информация");
        waysMenu = new JMenuItem("Список путей");
        waysMenu.addActionListener(waysListener);
        infoMenu.add(waysMenu);
        menuBar.add(infoMenu);
    }

    /**
     * Инициализация панели инструментов
     */
    private void initToolBar() {
        toolbar = new JToolBar();
        toolbar.setBorder(new BevelBorder(BevelBorder.RAISED));
        toolbar.addSeparator();
        
        saveButton = new JButton(new ImageIcon("save.png"));
        saveButton.addActionListener(saveListener);
        toolbar.add(saveButton);
        //openButton = new JButton(new ImageIcon("open.png"));
        //openButton.addActionListener(openListener);
        //toolbar.add(openButton);
        toolbar.addSeparator();
        toolbar.addSeparator();
        cursorButton = new JButton(new ImageIcon("cursor.png"));
        cursorButton.addActionListener(selectListener);
        toolbar.add(cursorButton);
        verticeButton = new JButton(new ImageIcon("uzel.png"));
        verticeButton.addActionListener(addCityListener);
        toolbar.add(verticeButton);
        edgeButton = new JButton(new ImageIcon("edge.png"));
        edgeButton.addActionListener(addWayListener);
        toolbar.add(edgeButton);
        
        //quitButton = new JButton(new ImageIcon("quit.png"));
        //quitButton.addActionListener(quitListener);
        //toolbar.add(quitButton);
        this.add(toolbar, BorderLayout.NORTH);
    }

    /**
     * Инициализация всех слушателей
     */
    private void initListeners() {
        // Режим добавления города
        addCityListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onAddCity();
            }
        };
        // Режим добавления пути
        addWayListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onAddWay();
            }
        };
        // Режим выбора
        selectListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onSelect();
            }
        };
        // Открыть файл
        openListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onOpen();
            }
        };
        // Сохранить файл
        saveListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onSave();
            }
        };
        // Выход
        quitListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onQuit();
            }
        };
        // Полноэкранный режим
        fullScreenListener = new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                onFullScreen(fullScreenMenu.getState());
            }
        };
        // Вывести список путей
        waysListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onInfoWays();
            }
        };
        selListener = new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                onSel();
            }
        };
        // Обработчик выхода
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent ev) {
                onQuit();
            }
        });
    }

    /**
     * Установка режима выбора
     */
    private void onSelect() {
        statusLabel.setText("Режим выбора");
        mainPanel.chooseSelectMode();
    }

    /**
     * Установка режима добавления города
     */
    private void onAddCity() {
        statusLabel.setText("Режим добавления узлов");
        mainPanel.chooseCityMode();
    }

    /**
     * Установка режима добавления пути
     */
    private void onAddWay() {
        statusLabel.setText("Режим добавления дуг");
        mainPanel.chooseWayMode();
    }
    private void onSel()
    {
        statusLabel.setText("Выберите узел");
        mainPanel.chooseSelMode();
    }

    /**
     * Переход в полноэкранный режим и обратно
     */
    private void onFullScreen(boolean on) {
        // Получение устройства
        GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
        GraphicsDevice device = environment.getDefaultScreenDevice();
        if (on) {
            //setUndecorated(true);
            // Игнорирование перерисовки
            setIgnoreRepaint(true);
            // Выключить изменение размера
            setResizable(false);
            // Перейти в полноэкранный режим
            device.setFullScreenWindow(this);
        } else {
            // Выключить полноэкранный режим
            device.setFullScreenWindow(null);
            //setUndecorated(false);
            // Не игнорировать перерисовку
            setIgnoreRepaint(false);
            // Включить изменение размера
            setResizable(true);
        }
    }

    /**
     * Диалог "список путей"
     */
    private void onInfoWays() {
        JDialog dialog = new WaysInfoDialog(this, true, mainPanel.getWorld());
        dialog.setVisible(true);
    }

    /**
     * Открыть файл
     */
    private void onOpen() {
        // Создаем диалог открытия
        JFileChooser fileChooser = new JFileChooser(currentFile);
        // Задаем файловые фильтры
        fileChooser.addChoosableFileFilter(WorldFileFilter.getWorldFilter());
        fileChooser.addChoosableFileFilter(WorldFileFilter.getXMLFilter());
        // Показываем диалог
        int result = fileChooser.showOpenDialog(this);
        if (result==JFileChooser.APPROVE_OPTION) {
            // Открываем файл
            currentFile = fileChooser.getSelectedFile();
            try {
                if (WorldFileFilter.getXMLFilter().accept(currentFile))
                    mainPanel.openWorldFromXML(currentFile);
                else
                    mainPanel.openWorldFromFile(currentFile);
                repaint();
                this.setTitle("Коммивояжер - " + currentFile.getName());
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(this, "Ошибка открытия файла: " +
                        ex.getMessage());
            } catch (ClassNotFoundException ex) {
                JOptionPane.showMessageDialog(this, "Неверный формат файла: " +
                        ex.getMessage());
            } catch (JDOMException ex) {
                JOptionPane.showMessageDialog(this, "Ошибка чтения XML: " +
                        ex.getMessage());
            }
        }
    }

    /**
     * Сохранить файл
     */
    private void onSave() {
        // Создаем диалог
        JFileChooser fileChooser = new JFileChooser(currentFile);
        // Задаем файловый фильтр
        fileChooser.addChoosableFileFilter(WorldFileFilter.getWorldFilter());
        fileChooser.addChoosableFileFilter(WorldFileFilter.getXMLFilter());
        // Показываем диалог
        int result = fileChooser.showSaveDialog(this);
        if (result==JFileChooser.APPROVE_OPTION) {
            // Сохраняем файл
            currentFile = fileChooser.getSelectedFile();
            final FileFilter currentFilter = fileChooser.getFileFilter();
            // Сохраняем в соответствии с выбранным фильтром
            if (currentFilter==WorldFileFilter.getXMLFilter()) {
                if (!WorldFileFilter.getXMLFilter().accept(currentFile)) {
                    currentFile = new File(currentFile.getPath() + ".xml");
                }
                try {
                    mainPanel.saveWorldToXML(currentFile);
                    this.setTitle("Коммивояжер - " + currentFile.getName());
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Ошибка открытия файла: " +
                            ex.getMessage());
                }
            } else {
                if (!WorldFileFilter.getWorldFilter().accept(currentFile)) {
                    currentFile = new File(currentFile.getPath() + ".world");
                }
                try {
                    mainPanel.saveWorldToFile(currentFile);
                    this.setTitle("Коммивояжер - " + currentFile.getName());
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Ошибка открытия файла: " +
                            ex.getMessage());
                }
            } 
        }        
    }

    /**
     * Обработчик выхода
     */
    private void onQuit() {
        onFullScreen(false);
        String[] vars = { "Да", "Нет" };
        int result = JOptionPane.showOptionDialog(this, "Действительно выйти?",
                "", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE,
                null, vars, "Да");
        if (result==JOptionPane.YES_OPTION)
            System.exit(0);
    }

    /**
     * Конструктор
     */
    public MainFrame(String s) {
        super(s);
        currentFile = null;
        setSize(800, 600);
        // Выбор BorderLayout
        this.setLayout(new BorderLayout());
        // Инициализация панелей
        initInfoPanel();
        initMainPanel();
        infoPanel.setListener(mainPanel);
        mainPanel.setListener(infoPanel);
        initStatusBar();
        JScrollPane scrollPanel = new JScrollPane(mainPanel);
        scrollPanel.setMinimumSize(new Dimension(200, 200));
        scrollPanel.setPreferredSize(new Dimension(500, 500));
        scrollPanel.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPanel.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        this.add(new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, scrollPanel, infoPanel),
                BorderLayout.CENTER);
        initListeners();
        initMenuBar();
        initToolBar();
        setVisible(true);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
    }
    /**
     * Главная функция
     */
    public static void main(String[] args) {
        new MainFrame("Редактор графов");
    }
}
