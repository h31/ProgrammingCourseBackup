package truckdriver.gui;

import java.util.Random;
import javax.swing.ImageIcon;
import truckdriver.City;
import truckdriver.God;
import truckdriver.GodCountPair;
import truckdriver.resources.Resources;

public class TabPanel extends javax.swing.JPanel {

    private int index;
    
    public TabPanel(int index) {
        this.index = index;
        initComponents();
        City city = Resources.cities.get(index);
        jtfCityTitle.setText(city.getTitle());
        for (GodCountPair item : city.getSelGods()) {
            if (item.getGod().equals(Resources.gods[0])) {
                jcbGold.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[1])) {
                jcbTree.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[2])) {
                jcbCoal.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[3])) {
                jcbIron.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[4])) {
                jcbFood.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[5])) {
                jcbWater.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[6])) {
                jcbStone.setSelected(true);
            }
            if (item.getGod().equals(Resources.gods[7])) {
                jcbClothes.setSelected(true);
            }
        }
    }
    
    public boolean setData() {
        City city = Resources.cities.get(index);
        city.getSelGods().clear();
        String title = jtfCityTitle.getText();
        if (title.length() == 0) return false;
        city.setTitle(title);
        Random random = new Random();
        God[] gods = Resources.gods;
        if (jcbGold.isSelected()) {
            GodCountPair item = new GodCountPair(gods[0], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbTree.isSelected()) {
            GodCountPair item = new GodCountPair(gods[1], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbCoal.isSelected()) {
            GodCountPair item = new GodCountPair(gods[2], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbIron.isSelected()) {
            GodCountPair item = new GodCountPair(gods[3], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbFood.isSelected()) {
            GodCountPair item = new GodCountPair(gods[4], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbWater.isSelected()) {
            GodCountPair item = new GodCountPair(gods[5], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbStone.isSelected()) {
            GodCountPair item = new GodCountPair(gods[6], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (jcbClothes.isSelected()) {
            GodCountPair item = new GodCountPair(gods[7], random.nextInt(50));
            city.getSelGods().add(item);
        }
        if (city.getSelGods().isEmpty()) return false;
        return true;
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jlTitle = new javax.swing.JLabel();
        jtfCityTitle = new javax.swing.JTextField();
        jpGodsCheck = new javax.swing.JPanel();
        jcbGold = new javax.swing.JCheckBox();
        jcbTree = new javax.swing.JCheckBox();
        jcbCoal = new javax.swing.JCheckBox();
        jcbIron = new javax.swing.JCheckBox();
        jcbClothes = new javax.swing.JCheckBox();
        jcbFood = new javax.swing.JCheckBox();
        jcbWater = new javax.swing.JCheckBox();
        jcbStone = new javax.swing.JCheckBox();

        jlTitle.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jlTitle.setText("Название города:");

        jtfCityTitle.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N

        jpGodsCheck.setBorder(javax.swing.BorderFactory.createTitledBorder(null, "Продаваемые товары", javax.swing.border.TitledBorder.DEFAULT_JUSTIFICATION, javax.swing.border.TitledBorder.DEFAULT_POSITION, new java.awt.Font("Tahoma", 0, 14))); // NOI18N

        jcbGold.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbGold.setText("Золото");

        jcbTree.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbTree.setText("Дерево");

        jcbCoal.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbCoal.setText("Уголь");

        jcbIron.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbIron.setText("Железо");

        jcbClothes.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbClothes.setText("Одежда");

        jcbFood.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbFood.setText("Еда");

        jcbWater.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbWater.setText("Вода");

        jcbStone.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jcbStone.setText("Камень");

        javax.swing.GroupLayout jpGodsCheckLayout = new javax.swing.GroupLayout(jpGodsCheck);
        jpGodsCheck.setLayout(jpGodsCheckLayout);
        jpGodsCheckLayout.setHorizontalGroup(
            jpGodsCheckLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpGodsCheckLayout.createSequentialGroup()
                .addGap(14, 14, 14)
                .addGroup(jpGodsCheckLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(jcbIron, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jcbCoal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jcbTree, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jcbGold, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(52, 52, 52)
                .addGroup(jpGodsCheckLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(jcbClothes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jcbStone, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jcbWater, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jcbFood, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(74, Short.MAX_VALUE))
        );
        jpGodsCheckLayout.setVerticalGroup(
            jpGodsCheckLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpGodsCheckLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpGodsCheckLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpGodsCheckLayout.createSequentialGroup()
                        .addComponent(jcbFood)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jcbWater)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jcbStone)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jcbClothes))
                    .addGroup(jpGodsCheckLayout.createSequentialGroup()
                        .addComponent(jcbGold)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jcbTree)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jcbCoal)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jcbIron)))
                .addContainerGap(25, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jlTitle)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jtfCityTitle, javax.swing.GroupLayout.PREFERRED_SIZE, 207, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jpGodsCheck, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(106, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfCityTitle, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlTitle))
                .addGap(18, 18, 18)
                .addComponent(jpGodsCheck, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(20, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JCheckBox jcbClothes;
    private javax.swing.JCheckBox jcbCoal;
    private javax.swing.JCheckBox jcbFood;
    private javax.swing.JCheckBox jcbGold;
    private javax.swing.JCheckBox jcbIron;
    private javax.swing.JCheckBox jcbStone;
    private javax.swing.JCheckBox jcbTree;
    private javax.swing.JCheckBox jcbWater;
    private javax.swing.JLabel jlTitle;
    private javax.swing.JPanel jpGodsCheck;
    private javax.swing.JTextField jtfCityTitle;
    // End of variables declaration//GEN-END:variables
}
