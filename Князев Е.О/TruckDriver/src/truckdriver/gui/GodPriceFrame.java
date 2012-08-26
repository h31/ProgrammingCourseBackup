package truckdriver.gui;

import java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import truckdriver.resources.Resources;
import truckdriver.Start;

public class GodPriceFrame extends javax.swing.JFrame {

    public GodPriceFrame() {
        initComponents();
        jlGold.setIcon(new ImageIcon(Resources.images[0]));
        jlTree.setIcon(new ImageIcon(Resources.images[1]));
        jlCoal.setIcon(new ImageIcon(Resources.images[2]));
        jlIron.setIcon(new ImageIcon(Resources.images[3]));
        jlFood.setIcon(new ImageIcon(Resources.images[4]));
        jlWater.setIcon(new ImageIcon(Resources.images[5]));
        jlStone.setIcon(new ImageIcon(Resources.images[6]));
        jlClothes.setIcon(new ImageIcon(Resources.images[7]));
        jtfGold.setText("" + Resources.gods[0].getPrice());
        jtfTree.setText("" + Resources.gods[1].getPrice());
        jtfCoal.setText("" + Resources.gods[2].getPrice());
        jtfIron.setText("" + Resources.gods[3].getPrice());
        jtfFood.setText("" + Resources.gods[4].getPrice());
        jtfWater.setText("" + Resources.gods[5].getPrice());
        jtfStone.setText("" + Resources.gods[6].getPrice());
        jtfClothes.setText("" + Resources.gods[7].getPrice());
        jtfTruckMoney.setText("50.0");
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

        jpGroupBox = new javax.swing.JPanel();
        jlGold = new javax.swing.JLabel();
        jtfGold = new javax.swing.JTextField();
        jtfTree = new javax.swing.JTextField();
        jlTree = new javax.swing.JLabel();
        jtfCoal = new javax.swing.JTextField();
        jlCoal = new javax.swing.JLabel();
        jtfIron = new javax.swing.JTextField();
        jlIron = new javax.swing.JLabel();
        jtfFood = new javax.swing.JTextField();
        jlFood = new javax.swing.JLabel();
        jtfWater = new javax.swing.JTextField();
        jlWater = new javax.swing.JLabel();
        jtfStone = new javax.swing.JTextField();
        jlStone = new javax.swing.JLabel();
        jtfClothes = new javax.swing.JTextField();
        jlClothes = new javax.swing.JLabel();
        jlTruckMoney = new javax.swing.JLabel();
        jtfTruckMoney = new javax.swing.JTextField();
        jbStartGame = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("TruckDriver [шаг 3 - деньги]");
        setMaximumSize(new java.awt.Dimension(300, 400));
        setMinimumSize(new java.awt.Dimension(300, 400));
        setName("frameGodPrice");
        setResizable(false);

        jpGroupBox.setBorder(javax.swing.BorderFactory.createTitledBorder(null, "Цены товаров", javax.swing.border.TitledBorder.DEFAULT_JUSTIFICATION, javax.swing.border.TitledBorder.DEFAULT_POSITION, new java.awt.Font("Tahoma", 0, 12))); // NOI18N

        jlGold.setText("Золото:");

        jlTree.setText("Дерево:");

        jlCoal.setText("Уголь:");

        jlIron.setText("Железо:");

        jlFood.setText("Еда:");

        jlWater.setText("Вода:");

        jlStone.setText("Камень:");

        jlClothes.setText("Одежда:");

        javax.swing.GroupLayout jpGroupBoxLayout = new javax.swing.GroupLayout(jpGroupBox);
        jpGroupBox.setLayout(jpGroupBoxLayout);
        jpGroupBoxLayout.setHorizontalGroup(
            jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpGroupBoxLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpGroupBoxLayout.createSequentialGroup()
                        .addComponent(jlCoal)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jtfCoal, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpGroupBoxLayout.createSequentialGroup()
                        .addComponent(jlIron)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jtfIron, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpGroupBoxLayout.createSequentialGroup()
                        .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlFood)
                            .addComponent(jlClothes))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jtfFood, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jtfClothes, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(jpGroupBoxLayout.createSequentialGroup()
                        .addComponent(jlWater)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jtfWater, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpGroupBoxLayout.createSequentialGroup()
                        .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlGold)
                            .addComponent(jlTree))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jtfGold, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jtfTree, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(jpGroupBoxLayout.createSequentialGroup()
                        .addComponent(jlStone)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jtfStone, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jpGroupBoxLayout.setVerticalGroup(
            jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpGroupBoxLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfGold, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlGold))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfTree, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlTree))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfCoal, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlCoal))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfIron, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlIron))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfFood, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlFood))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfWater, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlWater))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfStone, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlStone))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpGroupBoxLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jtfClothes, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlClothes))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jlTruckMoney.setText("Деньги грузовичка:");

        jbStartGame.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        jbStartGame.setText("Начать игру");
        jbStartGame.setFocusPainted(false);
        jbStartGame.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbStartGameActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jbStartGame, javax.swing.GroupLayout.PREFERRED_SIZE, 135, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jpGroupBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGroup(layout.createSequentialGroup()
                            .addGap(10, 10, 10)
                            .addComponent(jlTruckMoney)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(jtfTruckMoney, javax.swing.GroupLayout.PREFERRED_SIZE, 114, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap(41, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpGroupBox, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlTruckMoney)
                    .addComponent(jtfTruckMoney, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jbStartGame, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(33, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void jbStartGameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbStartGameActionPerformed
        try {
            Resources.gods[0].setPrice(Double.parseDouble(jtfGold.getText()));
            Resources.gods[1].setPrice(Double.parseDouble(jtfTree.getText()));
            Resources.gods[2].setPrice(Double.parseDouble(jtfCoal.getText()));
            Resources.gods[3].setPrice(Double.parseDouble(jtfIron.getText()));
            Resources.gods[4].setPrice(Double.parseDouble(jtfFood.getText()));
            Resources.gods[5].setPrice(Double.parseDouble(jtfWater.getText()));
            Resources.gods[6].setPrice(Double.parseDouble(jtfStone.getText()));
            Resources.gods[7].setPrice(Double.parseDouble(jtfClothes.getText()));
            Start.inter.getTruck().setMoney(Double.parseDouble(jtfTruckMoney.getText()));
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Неверно заданные данные!", 
                    "Ошибка", JOptionPane.ERROR_MESSAGE);
        }
        setVisible(false);
        new GameFrame().start();
    }//GEN-LAST:event_jbStartGameActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jbStartGame;
    private javax.swing.JLabel jlClothes;
    private javax.swing.JLabel jlCoal;
    private javax.swing.JLabel jlFood;
    private javax.swing.JLabel jlGold;
    private javax.swing.JLabel jlIron;
    private javax.swing.JLabel jlStone;
    private javax.swing.JLabel jlTree;
    private javax.swing.JLabel jlTruckMoney;
    private javax.swing.JLabel jlWater;
    private javax.swing.JPanel jpGroupBox;
    private javax.swing.JTextField jtfClothes;
    private javax.swing.JTextField jtfCoal;
    private javax.swing.JTextField jtfFood;
    private javax.swing.JTextField jtfGold;
    private javax.swing.JTextField jtfIron;
    private javax.swing.JTextField jtfStone;
    private javax.swing.JTextField jtfTree;
    private javax.swing.JTextField jtfTruckMoney;
    private javax.swing.JTextField jtfWater;
    // End of variables declaration//GEN-END:variables
}