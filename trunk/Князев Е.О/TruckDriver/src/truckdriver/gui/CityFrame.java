package truckdriver.gui;

import java.awt.Dimension;
import java.awt.Point;
import java.awt.Toolkit;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import truckdriver.City;
import truckdriver.resources.Resources;
import truckdriver.Start;

public class CityFrame extends javax.swing.JFrame {
    
    private List<TabPanel> tabs = new ArrayList<>();
    
    public CityFrame() {
        initComponents();
        jlError.setVisible(false);
        int count = Resources.cities.size();
        for (int i = 0; i < count; i++) {
            tabs.add(new TabPanel(i));
            jTabbedPane.addTab("Город " + (i + 1), tabs.get(tabs.size() - 1));
        }
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

        jTabbedPane = new javax.swing.JTabbedPane();
        jbNext = new javax.swing.JButton();
        jlError = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("TruckDriver [шаг 2 - настройка городов]");
        setResizable(false);

        jbNext.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jbNext.setText("Далее");
        jbNext.setFocusPainted(false);
        jbNext.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbNextActionPerformed(evt);
            }
        });

        jlError.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        jlError.setForeground(new java.awt.Color(204, 0, 0));
        jlError.setText("Город без имени или не продавающий товары!");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jlError)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 75, Short.MAX_VALUE)
                .addComponent(jbNext, javax.swing.GroupLayout.PREFERRED_SIZE, 144, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(22, 22, 22))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jTabbedPane, javax.swing.GroupLayout.PREFERRED_SIZE, 287, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jbNext, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlError))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jbNextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbNextActionPerformed
        jlError.setVisible(false);
        for (int i = 0; i < tabs.size(); i++) {
            if (!tabs.get(i).setData()) {
                jTabbedPane.setSelectedIndex(i);
                jlError.setVisible(true);
                return;
            }
        }
        Random random = new Random();
        for (int i = 0; i < Resources.cities.size(); i++) {
            boolean flag;
            Point p = null;
            do {
                flag = false;
                int x = random.nextInt(720 - City.WIDTH);
                int y = random.nextInt(460 - City.HEIGHT) + 20;
                p = new Point(x, y);
                for (City city : Resources.cities) {
                    Point p2 = city.getPosition();
                    int offsetX = 50;
                    int offsetY = 20;
                    if (p.x + City.WIDTH + offsetX > p2.x && 
                            p.x < p2.x + City.WIDTH + offsetX) {
                        if (p.y + City.HEIGHT + offsetY > p2.y && 
                                p.y < p2.y + City.HEIGHT + offsetY) {
                            flag = true;
                            break;
                        }
                    }
                }
            } while (flag);
            Resources.cities.get(i).setPosition(p);
        }
        setVisible(false);
        Start.inter.initialize();
        new GodPriceFrame().start();
    }//GEN-LAST:event_jbNextActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTabbedPane jTabbedPane;
    private javax.swing.JButton jbNext;
    private javax.swing.JLabel jlError;
    // End of variables declaration//GEN-END:variables
}
