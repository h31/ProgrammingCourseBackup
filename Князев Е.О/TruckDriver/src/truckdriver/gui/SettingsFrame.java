package truckdriver.gui;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.util.*;
import truckdriver.City;
import truckdriver.GodCountPair;
import truckdriver.resources.Resources;

public class SettingsFrame extends javax.swing.JFrame {

    public SettingsFrame() {
        initComponents();
    }
    
    public void start() {
        Dimension size = Toolkit.getDefaultToolkit().getScreenSize();
        int x = size.width / 2 - this.getSize().width / 2;
        int y = size.height / 2 - this.getSize().height / 2;
        setLocation(x, y);
        setVisible(true);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jlCityCount = new javax.swing.JLabel();
        jbCityGenerate = new javax.swing.JButton();
        jcbCityCount = new javax.swing.JComboBox();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jtaInformation = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("TruckDriver [шаг 1 - количество городов]");
        setMaximumSize(new java.awt.Dimension(470, 260));
        setMinimumSize(new java.awt.Dimension(470, 260));
        setName("settingsFrame");
        setResizable(false);

        jlCityCount.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jlCityCount.setText("Количество городов:");

        jbCityGenerate.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jbCityGenerate.setText("Создать города");
        jbCityGenerate.setFocusPainted(false);
        jbCityGenerate.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbCityGenerateActionPerformed(evt);
            }
        });

        jcbCityCount.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jcbCityCount.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "3", "4", "5", "6", "7", "8" }));

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Информация"));

        jScrollPane1.setBorder(null);

        jtaInformation.setBackground(new java.awt.Color(240, 240, 240));
        jtaInformation.setColumns(20);
        jtaInformation.setEditable(false);
        jtaInformation.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jtaInformation.setRows(5);
        jtaInformation.setTabSize(4);
        jtaInformation.setText("Старт игры осуществляется в 3 шага:\n1. Выбор количества городов\n2. Настройка городов, если не устраивает случайные параметры\n3. Установка цен на продаваемые товары и бюджет грузовика");
        jtaInformation.setBorder(null);
        jScrollPane1.setViewportView(jtaInformation);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1)
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(14, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(jbCityGenerate, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(0, 190, Short.MAX_VALUE)
                                .addComponent(jlCityCount)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jcbCityCount, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 7, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jcbCityCount, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlCityCount))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jbCityGenerate, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(50, 50, 50))
        );
    }// </editor-fold>//GEN-END:initComponents

    private List<GodCountPair> generateSelGods() {
        List<GodCountPair> gods = new ArrayList();
        Random random = new Random();
        int count = random.nextInt(4) + 2;
        Set set = new HashSet();
        for (int i = 0; i < count; i++) {
            int index = random.nextInt(Resources.gods.length);
            while (set.contains(index)) {
                index = random.nextInt(Resources.gods.length);
            }
            set.add(index);
            GodCountPair item = new GodCountPair(Resources.gods[index], 100);
            gods.add(item);
        }
        return gods;
    }
    
    private void jbCityGenerateActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbCityGenerateActionPerformed
        int count = Integer.parseInt((String)jcbCityCount.getSelectedItem());
        Random random = new Random();
        Set set = new HashSet();
        for (int i = 0; i < count; i++) {
            City city = new City();
            int index = random.nextInt(Resources.cityNames.length);
            while (set.contains(index)) {
                index = random.nextInt(Resources.cityNames.length);
            }
            set.add(index);
            String title = Resources.cityNames[index];
            city.setTitle(title);
            city.setSelGods(generateSelGods());
            Resources.cities.add(city);
        }
        set.clear();
        setVisible(false);
        new CityFrame().start();
    }//GEN-LAST:event_jbCityGenerateActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton jbCityGenerate;
    private javax.swing.JComboBox jcbCityCount;
    private javax.swing.JLabel jlCityCount;
    private javax.swing.JTextArea jtaInformation;
    // End of variables declaration//GEN-END:variables
}
