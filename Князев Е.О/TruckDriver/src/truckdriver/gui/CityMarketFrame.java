package truckdriver.gui;

import truckdriver.resources.Resources;
import java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import truckdriver.*;

public class CityMarketFrame extends javax.swing.JFrame {

    private City city;
    public static final double add = 1.25;
    
    public CityMarketFrame() {
        initComponents();
        jlGold.setIcon(new ImageIcon(Resources.images[0]));
        jlTree.setIcon(new ImageIcon(Resources.images[1]));
        jlCoal.setIcon(new ImageIcon(Resources.images[2]));
        jlIron.setIcon(new ImageIcon(Resources.images[3]));
        jlFood.setIcon(new ImageIcon(Resources.images[4]));
        jlWater.setIcon(new ImageIcon(Resources.images[5]));
        jlStone.setIcon(new ImageIcon(Resources.images[6]));
        jlClothes.setIcon(new ImageIcon(Resources.images[7]));
        jlGold2.setIcon(new ImageIcon(Resources.images[0]));
        jlTree2.setIcon(new ImageIcon(Resources.images[1]));
        jlCoal2.setIcon(new ImageIcon(Resources.images[2]));
        jlIron2.setIcon(new ImageIcon(Resources.images[3]));
        jlFood2.setIcon(new ImageIcon(Resources.images[4]));
        jlWater2.setIcon(new ImageIcon(Resources.images[5]));
        jlStone2.setIcon(new ImageIcon(Resources.images[6]));
        jlClothes2.setIcon(new ImageIcon(Resources.images[7]));
        jlGoldPrice.setText(Resources.gods[0].getPrice() + "");
        jlTreePrice.setText(Resources.gods[1].getPrice() + "");
        jlCoalPrice.setText(Resources.gods[2].getPrice() + "");
        jlIronPrice.setText(Resources.gods[3].getPrice() + "");
        jlFoodPrice.setText(Resources.gods[4].getPrice() + "");
        jlWaterPrice.setText(Resources.gods[5].getPrice() + "");
        jlStonePrice.setText(Resources.gods[6].getPrice() + "");
        jlClothesPrice.setText(Resources.gods[7].getPrice() + "");
        jlGoldPrice2.setText(Resources.gods[0].getPrice() * add + "");
        jlTreePrice2.setText(Resources.gods[1].getPrice() * add + "");
        jlCoalPrice2.setText(Resources.gods[2].getPrice() * add + "");
        jlIronPrice2.setText(Resources.gods[3].getPrice() * add + "");
        jlFoodPrice2.setText(Resources.gods[4].getPrice() * add + "");
        jlWaterPrice2.setText(Resources.gods[5].getPrice() * add + "");
        jlStonePrice2.setText(Resources.gods[6].getPrice() * add + "");
        jlClothesPrice2.setText(Resources.gods[7].getPrice() * add + "");
    }
    
    public void start(City city) {
        this.city = city;
        jlCityTitle.setText(this.city.getTitle());
        for (GodCountPair item : city.getSelGods()) {
            String god = item.getGod().getTitle();
            switch (god) {
                case "Золото" : jtfGold.setEnabled(true); break;
                case "Дерево" : jtfTree.setEnabled(true); break;
                case "Уголь"  : jtfCoal.setEnabled(true); break;
                case "Железо" : jtfIron.setEnabled(true); break;
                case "Еда"    : jtfFood.setEnabled(true); break;
                case "Вода"   : jtfWater.setEnabled(true); break;
                case "Камень" : jtfStone.setEnabled(true); break;
                case "Одежда" : jtfClothes.setEnabled(true); break;
            }
        }
        for (GodCountPair item : city.getBuyGods()) {
            String god = item.getGod().getTitle();
            switch (god) {
                case "Золото" : jtfGold2.setEnabled(true); break;
                case "Дерево" : jtfTree2.setEnabled(true); break;
                case "Уголь"  : jtfCoal2.setEnabled(true); break;
                case "Железо" : jtfIron2.setEnabled(true); break;
                case "Еда"    : jtfFood2.setEnabled(true); break;
                case "Вода"   : jtfWater2.setEnabled(true); break;
                case "Камень" : jtfStone2.setEnabled(true); break;
                case "Одежда" : jtfClothes2.setEnabled(true); break;
            }
        }
        Dimension size = Toolkit.getDefaultToolkit().getScreenSize();
        int x = size.width / 2 - this.getSize().width / 2;
        int y = size.height / 2 - this.getSize().height / 2;
        setLocation(x, y);
        updateData();
        setVisible(true);
    }
    
    private void updateData() {
        jlTruckMoney.setText("Ваши деньги: " + Start.inter.getTruck().getMoney());
        for (GodCountPair item : city.getBuyGods()) {
            String god = item.getGod().getTitle();
            switch (god) {
                case "Золото" : jlNeedGold.setText("" + item.getCount()); break;
                case "Дерево" : jlNeedTree.setText("" + item.getCount()); break;
                case "Уголь"  : jlNeedCoal.setText("" + item.getCount()); break;
                case "Железо" : jlNeedIron.setText("" + item.getCount()); break;
                case "Еда"    : jlNeedFood.setText("" + item.getCount()); break;
                case "Вода"   : jlNeedWater.setText("" + item.getCount()); break;
                case "Камень" : jlNeedStone.setText("" + item.getCount()); break;
                case "Одежда" : jlNeedClothes.setText("" + item.getCount()); break;
            }
        }
        for (GodCountPair item : Start.inter.getTruck().getGods()) {
            String god = item.getGod().getTitle();
            switch (god) {
                case "Золото" : jlHasGold.setText("" + item.getCount()); break;
                case "Дерево" : jlHasTree.setText("" + item.getCount()); break;
                case "Уголь"  : jlHasCoal.setText("" + item.getCount()); break;
                case "Железо" : jlHasIron.setText("" + item.getCount()); break;
                case "Еда"    : jlHasFood.setText("" + item.getCount()); break;
                case "Вода"   : jlHasWater.setText("" + item.getCount()); break;
                case "Камень" : jlHasStone.setText("" + item.getCount()); break;
                case "Одежда" : jlHasClothes.setText("" + item.getCount()); break;
            }
        }
        for (GodCountPair item : city.getSelGods()) {
            String god = item.getGod().getTitle();
            switch (god) {
                case "Золото" : jlCityGold.setText("" + item.getCount()); break;
                case "Дерево" : jlCityTree.setText("" + item.getCount()); break;
                case "Уголь"  : jlCityCoal.setText("" + item.getCount()); break;
                case "Железо" : jlCityIron.setText("" + item.getCount()); break;
                case "Еда"    : jlCityFood.setText("" + item.getCount()); break;
                case "Вода"   : jlCityWater.setText("" + item.getCount()); break;
                case "Камень" : jlCityStone.setText("" + item.getCount()); break;
                case "Одежда" : jlCityClothes.setText("" + item.getCount()); break;
            }
        }
    }
    
    private double getGeneralSumm() {
        double summ = 0;
        God[] gods = Resources.gods;
        try
        {
            summ += Integer.parseInt(jtfGold.getText()) * gods[0].getPrice();
            summ += Integer.parseInt(jtfTree.getText()) * gods[1].getPrice();
            summ += Integer.parseInt(jtfCoal.getText()) * gods[2].getPrice();
            summ += Integer.parseInt(jtfIron.getText()) * gods[3].getPrice();
            summ += Integer.parseInt(jtfFood.getText()) * gods[4].getPrice();
            summ += Integer.parseInt(jtfWater.getText()) * gods[5].getPrice();
            summ += Integer.parseInt(jtfStone.getText()) * gods[6].getPrice();
            summ += Integer.parseInt(jtfClothes.getText()) * gods[7].getPrice();
        }
        catch(Exception ex) {
            JOptionPane.showMessageDialog(this, "Неверно заданные данные!", 
                    "Ошибка", JOptionPane.ERROR_MESSAGE);
        }
        return summ;
    }
    
    private int canSel() {
        int sel = 1;
        try {
            int[] userWant = {
                Integer.parseInt(jtfGold2.getText()),
                Integer.parseInt(jtfTree2.getText()),
                Integer.parseInt(jtfCoal2.getText()),
                Integer.parseInt(jtfIron2.getText()),
                Integer.parseInt(jtfFood2.getText()),
                Integer.parseInt(jtfWater2.getText()),
                Integer.parseInt(jtfStone2.getText()),
                Integer.parseInt(jtfClothes2.getText())
            };
            int[] need = {
                Integer.parseInt(jlNeedGold.getText()),
                Integer.parseInt(jlNeedTree.getText()),
                Integer.parseInt(jlNeedCoal.getText()),
                Integer.parseInt(jlNeedIron.getText()),
                Integer.parseInt(jlNeedFood.getText()),
                Integer.parseInt(jlNeedWater.getText()),
                Integer.parseInt(jlNeedStone.getText()),
                Integer.parseInt(jlNeedClothes.getText())
            };
            int[] has = {
                Integer.parseInt(jlHasGold.getText()),
                Integer.parseInt(jlHasTree.getText()),
                Integer.parseInt(jlHasCoal.getText()),
                Integer.parseInt(jlHasIron.getText()),
                Integer.parseInt(jlHasFood.getText()),
                Integer.parseInt(jlHasWater.getText()),
                Integer.parseInt(jlHasStone.getText()),
                Integer.parseInt(jlHasClothes.getText())
            };
            for (int i = 0; i < 8; i++) {
                if (userWant[i] > need[i] || userWant[i] > has[i]) {
                    sel = 0;
                    break;
                }
            }   
        }
        catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Неверно заданные данные!", 
                    "Ошибка", JOptionPane.ERROR_MESSAGE);
            sel = -1;
            return sel;
        }
        return sel;
    }
    
    private int canBuy() {
        int buy = 1;
        try {
            int[] userWant = {
                Integer.parseInt(jtfGold.getText()),
                Integer.parseInt(jtfTree.getText()),
                Integer.parseInt(jtfCoal.getText()),
                Integer.parseInt(jtfIron.getText()),
                Integer.parseInt(jtfFood.getText()),
                Integer.parseInt(jtfWater.getText()),
                Integer.parseInt(jtfStone.getText()),
                Integer.parseInt(jtfClothes.getText())
            };
            int[] has = {
                Integer.parseInt(jlCityGold.getText()),
                Integer.parseInt(jlCityTree.getText()),
                Integer.parseInt(jlCityCoal.getText()),
                Integer.parseInt(jlCityIron.getText()),
                Integer.parseInt(jlCityFood.getText()),
                Integer.parseInt(jlCityWater.getText()),
                Integer.parseInt(jlCityStone.getText()),
                Integer.parseInt(jlCityClothes.getText())
            };
            for (int i = 0; i < 8; i++) {
                if (userWant[i] > has[i]) {
                    buy = 0;
                    break;
                }
            }   
        }
        catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Неверно заданные данные!", 
                    "Ошибка", JOptionPane.ERROR_MESSAGE);
            buy = -1;
            return buy;
        }
        return buy;
    }
    
    private double getSelSumm() {
        double summ = 0;
        God[] gods = Resources.gods;
        try
        {
            summ += Integer.parseInt(jtfGold2.getText()) * gods[0].getPrice() * add;
            summ += Integer.parseInt(jtfTree2.getText()) * gods[1].getPrice() * add;
            summ += Integer.parseInt(jtfCoal2.getText()) * gods[2].getPrice() * add;
            summ += Integer.parseInt(jtfIron2.getText()) * gods[3].getPrice() * add;
            summ += Integer.parseInt(jtfFood2.getText()) * gods[4].getPrice() * add;
            summ += Integer.parseInt(jtfWater2.getText()) * gods[5].getPrice() * add;
            summ += Integer.parseInt(jtfStone2.getText()) * gods[6].getPrice() * add;
            summ += Integer.parseInt(jtfClothes2.getText()) * gods[7].getPrice() * add;
        }
        catch(Exception ex) {
            JOptionPane.showMessageDialog(this, "Неверно заданные данные!", 
                    "Ошибка", JOptionPane.ERROR_MESSAGE);
        }
        return summ;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jlCityTitle = new javax.swing.JLabel();
        jTabbedPane = new javax.swing.JTabbedPane();
        jpBuy = new javax.swing.JPanel();
        jpSelGods = new javax.swing.JPanel();
        jlGold = new javax.swing.JLabel();
        jlTree = new javax.swing.JLabel();
        jlCoal = new javax.swing.JLabel();
        jlIron = new javax.swing.JLabel();
        jlFood = new javax.swing.JLabel();
        jlWater = new javax.swing.JLabel();
        jlStone = new javax.swing.JLabel();
        jlClothes = new javax.swing.JLabel();
        jtfGold = new javax.swing.JTextField();
        jtfTree = new javax.swing.JTextField();
        jtfCoal = new javax.swing.JTextField();
        jtfIron = new javax.swing.JTextField();
        jtfFood = new javax.swing.JTextField();
        jtfWater = new javax.swing.JTextField();
        jtfStone = new javax.swing.JTextField();
        jtfClothes = new javax.swing.JTextField();
        jlSelGod = new javax.swing.JLabel();
        jlSelCount = new javax.swing.JLabel();
        jbCreateScheme = new javax.swing.JButton();
        jlPrice = new javax.swing.JLabel();
        jlGoldPrice = new javax.swing.JLabel();
        jlTreePrice = new javax.swing.JLabel();
        jlCoalPrice = new javax.swing.JLabel();
        jlIronPrice = new javax.swing.JLabel();
        jlFoodPrice = new javax.swing.JLabel();
        jlWaterPrice = new javax.swing.JLabel();
        jlStonePrice = new javax.swing.JLabel();
        jlClothesPrice = new javax.swing.JLabel();
        jlCityHas = new javax.swing.JLabel();
        jlCityGold = new javax.swing.JLabel();
        jlCityTree = new javax.swing.JLabel();
        jlCityCoal = new javax.swing.JLabel();
        jlCityIron = new javax.swing.JLabel();
        jlCityFood = new javax.swing.JLabel();
        jlCityWater = new javax.swing.JLabel();
        jlCityStone = new javax.swing.JLabel();
        jlCityClothes = new javax.swing.JLabel();
        jlGeneralSumm = new javax.swing.JLabel();
        jlBuyGods = new javax.swing.JButton();
        jpSel = new javax.swing.JPanel();
        jpBuyGods = new javax.swing.JPanel();
        jlGold2 = new javax.swing.JLabel();
        jlTree2 = new javax.swing.JLabel();
        jlCoal2 = new javax.swing.JLabel();
        jlIron2 = new javax.swing.JLabel();
        jlFood2 = new javax.swing.JLabel();
        jlWater2 = new javax.swing.JLabel();
        jlStone2 = new javax.swing.JLabel();
        jlClothes2 = new javax.swing.JLabel();
        jtfGold2 = new javax.swing.JTextField();
        jtfTree2 = new javax.swing.JTextField();
        jtfCoal2 = new javax.swing.JTextField();
        jtfIron2 = new javax.swing.JTextField();
        jtfFood2 = new javax.swing.JTextField();
        jtfWater2 = new javax.swing.JTextField();
        jtfStone2 = new javax.swing.JTextField();
        jtfClothes2 = new javax.swing.JTextField();
        jlGod2 = new javax.swing.JLabel();
        jlCount = new javax.swing.JLabel();
        jbAccept = new javax.swing.JButton();
        jlPrice2 = new javax.swing.JLabel();
        jlGoldPrice2 = new javax.swing.JLabel();
        jlTreePrice2 = new javax.swing.JLabel();
        jlCoalPrice2 = new javax.swing.JLabel();
        jlIronPrice2 = new javax.swing.JLabel();
        jlFoodPrice2 = new javax.swing.JLabel();
        jlWaterPrice2 = new javax.swing.JLabel();
        jlStonePrice2 = new javax.swing.JLabel();
        jlClothesPrice2 = new javax.swing.JLabel();
        jlNeedStone = new javax.swing.JLabel();
        jlNeedIron = new javax.swing.JLabel();
        jlNeed = new javax.swing.JLabel();
        jlNeedWater = new javax.swing.JLabel();
        jlNeedFood = new javax.swing.JLabel();
        jlNeedTree = new javax.swing.JLabel();
        jlNeedClothes = new javax.swing.JLabel();
        jlNeedCoal = new javax.swing.JLabel();
        jlNeedGold = new javax.swing.JLabel();
        jlHasGods = new javax.swing.JLabel();
        jlHasGold = new javax.swing.JLabel();
        jlHasTree = new javax.swing.JLabel();
        jlHasCoal = new javax.swing.JLabel();
        jlHasIron = new javax.swing.JLabel();
        jlHasFood = new javax.swing.JLabel();
        jlHasWater = new javax.swing.JLabel();
        jlHasStone = new javax.swing.JLabel();
        jlHasClothes = new javax.swing.JLabel();
        jlSumm = new javax.swing.JLabel();
        jbSel = new javax.swing.JButton();
        jlTruckMoney = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("TruckDriver [торговля]");
        setAlwaysOnTop(true);
        setModalExclusionType(java.awt.Dialog.ModalExclusionType.APPLICATION_EXCLUDE);
        setResizable(false);

        jlCityTitle.setFont(new java.awt.Font("Tahoma", 3, 14)); // NOI18N
        jlCityTitle.setText("Город");

        jpSelGods.setBorder(javax.swing.BorderFactory.createTitledBorder(null, "Купить товары", javax.swing.border.TitledBorder.DEFAULT_JUSTIFICATION, javax.swing.border.TitledBorder.DEFAULT_POSITION, new java.awt.Font("Tahoma", 3, 12))); // NOI18N

        jlGold.setText("Золото:");

        jlTree.setText("Дерево:");

        jlCoal.setText("Уголь:");

        jlIron.setText("Железо:");

        jlFood.setText("Еда:");

        jlWater.setText("Вода:");

        jlStone.setText("Камень:");

        jlClothes.setText("Одежда:");

        jtfGold.setText("0");
        jtfGold.setEnabled(false);

        jtfTree.setText("0");
        jtfTree.setEnabled(false);

        jtfCoal.setText("0");
        jtfCoal.setEnabled(false);

        jtfIron.setText("0");
        jtfIron.setEnabled(false);

        jtfFood.setText("0");
        jtfFood.setEnabled(false);

        jtfWater.setText("0");
        jtfWater.setEnabled(false);

        jtfStone.setText("0");
        jtfStone.setEnabled(false);

        jtfClothes.setText("0");
        jtfClothes.setEnabled(false);

        jlSelGod.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlSelGod.setText("Товар:");

        jlSelCount.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlSelCount.setText("Количество:");

        jbCreateScheme.setText("Подсчитать сумму");
        jbCreateScheme.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbCreateSchemeActionPerformed(evt);
            }
        });

        jlPrice.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlPrice.setText("Цена:");

        jlGoldPrice.setText("0.0");

        jlTreePrice.setText("0.0");

        jlCoalPrice.setText("0.0");

        jlIronPrice.setText("0.0");

        jlFoodPrice.setText("0.0");

        jlWaterPrice.setText("0.0");

        jlStonePrice.setText("0.0");

        jlClothesPrice.setText("0.0");

        jlCityHas.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlCityHas.setText("Есть:");

        jlCityGold.setText("0");

        jlCityTree.setText("0");

        jlCityCoal.setText("0");

        jlCityIron.setText("0");

        jlCityFood.setText("0");

        jlCityWater.setText("0");

        jlCityStone.setText("0");

        jlCityClothes.setText("0");

        javax.swing.GroupLayout jpSelGodsLayout = new javax.swing.GroupLayout(jpSelGods);
        jpSelGods.setLayout(jpSelGodsLayout);
        jpSelGodsLayout.setHorizontalGroup(
            jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpSelGodsLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpSelGodsLayout.createSequentialGroup()
                        .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlGold)
                            .addComponent(jlTree)
                            .addComponent(jlIron)
                            .addComponent(jlCoal)
                            .addComponent(jlWater)
                            .addComponent(jlFood)
                            .addComponent(jlStone)
                            .addComponent(jlClothes)
                            .addComponent(jlSelGod))
                        .addGap(18, 18, 18)
                        .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jpSelGodsLayout.createSequentialGroup()
                                .addComponent(jlSelCount)
                                .addGap(18, 18, 18)
                                .addComponent(jlPrice))
                            .addGroup(jpSelGodsLayout.createSequentialGroup()
                                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jtfGold)
                                    .addComponent(jtfTree)
                                    .addComponent(jtfCoal)
                                    .addComponent(jtfIron)
                                    .addComponent(jtfFood)
                                    .addComponent(jtfWater)
                                    .addComponent(jtfStone)
                                    .addComponent(jtfClothes, javax.swing.GroupLayout.PREFERRED_SIZE, 74, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(18, 18, 18)
                                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jpSelGodsLayout.createSequentialGroup()
                                        .addComponent(jlStonePrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jlCityStone, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(jpSelGodsLayout.createSequentialGroup()
                                        .addComponent(jlClothesPrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jlCityClothes, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(jpSelGodsLayout.createSequentialGroup()
                                        .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jlGoldPrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlTreePrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlCoalPrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlIronPrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlFoodPrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlWaterPrice, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(jlCityHas)
                                            .addComponent(jlCityWater, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlCityFood, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlCityIron, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlCityCoal, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlCityTree, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(jlCityGold, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)))))))
                    .addComponent(jbCreateScheme, javax.swing.GroupLayout.PREFERRED_SIZE, 190, javax.swing.GroupLayout.PREFERRED_SIZE)))
        );
        jpSelGodsLayout.setVerticalGroup(
            jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpSelGodsLayout.createSequentialGroup()
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlSelGod)
                    .addComponent(jlSelCount)
                    .addComponent(jlPrice)
                    .addComponent(jlCityHas))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlGold)
                    .addComponent(jtfGold, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlGoldPrice)
                    .addComponent(jlCityGold))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlTree)
                    .addComponent(jtfTree, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlTreePrice)
                    .addComponent(jlCityTree))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlCoal)
                    .addComponent(jtfCoal, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlCoalPrice)
                    .addComponent(jlCityCoal))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlIron)
                    .addComponent(jtfIron, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlIronPrice)
                    .addComponent(jlCityIron))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlFood)
                    .addComponent(jtfFood, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlFoodPrice)
                    .addComponent(jlCityFood))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlWater)
                    .addComponent(jtfWater, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlWaterPrice)
                    .addComponent(jlCityWater))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlStone)
                    .addComponent(jtfStone, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlStonePrice)
                    .addComponent(jlCityStone))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpSelGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlClothes)
                    .addComponent(jtfClothes, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlClothesPrice)
                    .addComponent(jlCityClothes))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jbCreateScheme)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jlGeneralSumm.setText("Общая сумма:");

        jlBuyGods.setText("Купить");
        jlBuyGods.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jlBuyGodsActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jpBuyLayout = new javax.swing.GroupLayout(jpBuy);
        jpBuy.setLayout(jpBuyLayout);
        jpBuyLayout.setHorizontalGroup(
            jpBuyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpBuyLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpBuyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpBuyLayout.createSequentialGroup()
                        .addGap(0, 282, Short.MAX_VALUE)
                        .addComponent(jlBuyGods, javax.swing.GroupLayout.PREFERRED_SIZE, 107, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpBuyLayout.createSequentialGroup()
                        .addGroup(jpBuyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlGeneralSumm)
                            .addComponent(jpSelGods, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jpBuyLayout.setVerticalGroup(
            jpBuyLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpBuyLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpSelGods, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jlGeneralSumm)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 75, Short.MAX_VALUE)
                .addComponent(jlBuyGods)
                .addContainerGap())
        );

        jTabbedPane.addTab("Покупка", jpBuy);

        jpBuyGods.setBorder(javax.swing.BorderFactory.createTitledBorder(null, "Продать товары", javax.swing.border.TitledBorder.DEFAULT_JUSTIFICATION, javax.swing.border.TitledBorder.DEFAULT_POSITION, new java.awt.Font("Tahoma", 3, 12))); // NOI18N

        jlGold2.setText("Золото:");

        jlTree2.setText("Дерево:");

        jlCoal2.setText("Уголь:");

        jlIron2.setText("Железо:");

        jlFood2.setText("Еда:");

        jlWater2.setText("Вода:");

        jlStone2.setText("Камень:");

        jlClothes2.setText("Одежда:");

        jtfGold2.setText("0");
        jtfGold2.setEnabled(false);

        jtfTree2.setText("0");
        jtfTree2.setEnabled(false);

        jtfCoal2.setText("0");
        jtfCoal2.setEnabled(false);

        jtfIron2.setText("0");
        jtfIron2.setEnabled(false);

        jtfFood2.setText("0");
        jtfFood2.setEnabled(false);

        jtfWater2.setText("0");
        jtfWater2.setEnabled(false);

        jtfStone2.setText("0");
        jtfStone2.setEnabled(false);

        jtfClothes2.setText("0");
        jtfClothes2.setEnabled(false);

        jlGod2.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlGod2.setText("Товар:");

        jlCount.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlCount.setText("Количество:");

        jbAccept.setText("Подсчитать сумму");
        jbAccept.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbAcceptActionPerformed(evt);
            }
        });

        jlPrice2.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlPrice2.setText("Цена:");

        jlGoldPrice2.setText("0.0");

        jlTreePrice2.setText("0.0");

        jlCoalPrice2.setText("0.0");

        jlIronPrice2.setText("0.0");

        jlFoodPrice2.setText("0.0");

        jlWaterPrice2.setText("0.0");

        jlStonePrice2.setText("0.0");

        jlClothesPrice2.setText("0.0");

        jlNeedStone.setText("0");

        jlNeedIron.setText("0");

        jlNeed.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlNeed.setText("Нужно:");

        jlNeedWater.setText("0");

        jlNeedFood.setText("0");

        jlNeedTree.setText("0");

        jlNeedClothes.setText("0");

        jlNeedCoal.setText("0");

        jlNeedGold.setText("0");

        jlHasGods.setFont(new java.awt.Font("Tahoma", 2, 12)); // NOI18N
        jlHasGods.setText("У вас:");

        jlHasGold.setText("0");

        jlHasTree.setText("0");

        jlHasCoal.setText("0");

        jlHasIron.setText("0");

        jlHasFood.setText("0");

        jlHasWater.setText("0");

        jlHasStone.setText("0");

        jlHasClothes.setText("0");

        javax.swing.GroupLayout jpBuyGodsLayout = new javax.swing.GroupLayout(jpBuyGods);
        jpBuyGods.setLayout(jpBuyGodsLayout);
        jpBuyGodsLayout.setHorizontalGroup(
            jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpBuyGodsLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpBuyGodsLayout.createSequentialGroup()
                        .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlGold2)
                            .addComponent(jlTree2)
                            .addComponent(jlIron2)
                            .addComponent(jlCoal2)
                            .addComponent(jlWater2)
                            .addComponent(jlFood2)
                            .addComponent(jlStone2)
                            .addComponent(jlClothes2)
                            .addComponent(jlGod2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlCount)
                            .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(jtfGold2)
                                .addComponent(jtfTree2)
                                .addComponent(jtfCoal2)
                                .addComponent(jtfIron2)
                                .addComponent(jtfFood2)
                                .addComponent(jtfWater2)
                                .addComponent(jtfStone2)
                                .addComponent(jtfClothes2, javax.swing.GroupLayout.PREFERRED_SIZE, 74, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(18, 18, 18)
                        .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jpBuyGodsLayout.createSequentialGroup()
                                .addComponent(jlClothesPrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jlNeedClothes, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jlHasClothes, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jpBuyGodsLayout.createSequentialGroup()
                                .addComponent(jlStonePrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jlNeedStone, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jlHasStone, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jpBuyGodsLayout.createSequentialGroup()
                                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jlPrice2)
                                    .addComponent(jlWaterPrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlFoodPrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlIronPrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlCoalPrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlTreePrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlGoldPrice2, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jlNeed)
                                    .addComponent(jlNeedWater, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlNeedFood, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlNeedIron, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlNeedCoal, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlNeedTree, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlNeedGold, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jlHasGods)
                                    .addComponent(jlHasWater, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlHasFood, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlHasIron, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlHasCoal, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlHasTree, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jlHasGold, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                    .addComponent(jbAccept, javax.swing.GroupLayout.PREFERRED_SIZE, 190, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jpBuyGodsLayout.setVerticalGroup(
            jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpBuyGodsLayout.createSequentialGroup()
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlGod2)
                    .addComponent(jlCount)
                    .addComponent(jlPrice2)
                    .addComponent(jlNeed)
                    .addComponent(jlHasGods))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlGold2)
                    .addComponent(jtfGold2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlGoldPrice2)
                    .addComponent(jlNeedGold)
                    .addComponent(jlHasGold))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlTree2)
                    .addComponent(jtfTree2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlTreePrice2)
                    .addComponent(jlNeedTree)
                    .addComponent(jlHasTree))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlCoal2)
                    .addComponent(jtfCoal2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlCoalPrice2)
                    .addComponent(jlNeedCoal)
                    .addComponent(jlHasCoal))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlIron2)
                    .addComponent(jtfIron2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlIronPrice2)
                    .addComponent(jlNeedIron)
                    .addComponent(jlHasIron))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlFood2)
                    .addComponent(jtfFood2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlFoodPrice2)
                    .addComponent(jlNeedFood)
                    .addComponent(jlHasFood))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlWater2)
                    .addComponent(jtfWater2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlWaterPrice2)
                    .addComponent(jlNeedWater)
                    .addComponent(jlHasWater))
                .addGap(10, 10, 10)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlStone2)
                    .addComponent(jtfStone2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlStonePrice2)
                    .addComponent(jlNeedStone)
                    .addComponent(jlHasStone))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jpBuyGodsLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jlClothes2)
                    .addComponent(jtfClothes2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jlClothesPrice2)
                    .addComponent(jlNeedClothes)
                    .addComponent(jlHasClothes))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jbAccept)
                .addContainerGap(12, Short.MAX_VALUE))
        );

        jlSumm.setText("Сумма сделки:");

        jbSel.setText("Продать");
        jbSel.setToolTipText("");
        jbSel.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbSelActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jpSelLayout = new javax.swing.GroupLayout(jpSel);
        jpSel.setLayout(jpSelLayout);
        jpSelLayout.setHorizontalGroup(
            jpSelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpSelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpSelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpSelLayout.createSequentialGroup()
                        .addGap(0, 282, Short.MAX_VALUE)
                        .addComponent(jbSel, javax.swing.GroupLayout.PREFERRED_SIZE, 107, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpSelLayout.createSequentialGroup()
                        .addComponent(jlSumm)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(jpBuyGods, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        jpSelLayout.setVerticalGroup(
            jpSelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpSelLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpBuyGods, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jlSumm)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 70, Short.MAX_VALUE)
                .addComponent(jbSel)
                .addContainerGap())
        );

        jTabbedPane.addTab("Продажа", jpSel);

        jlTruckMoney.setFont(new java.awt.Font("Tahoma", 3, 12)); // NOI18N
        jlTruckMoney.setText("Ваши деньги:");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jlCityTitle, javax.swing.GroupLayout.PREFERRED_SIZE, 283, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jlTruckMoney, javax.swing.GroupLayout.PREFERRED_SIZE, 304, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jTabbedPane)
                        .addContainerGap())))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jlCityTitle)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jTabbedPane, javax.swing.GroupLayout.PREFERRED_SIZE, 455, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jlTruckMoney)
                .addContainerGap(18, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jbCreateSchemeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbCreateSchemeActionPerformed
        int state = canBuy();
        if (state == 0) {
            JOptionPane.showMessageDialog(this, "В городе недостаточно товара!", 
                "Ошибка", JOptionPane.ERROR_MESSAGE);
            return;
        }
        else if (state == -1) return;
        double summ = getGeneralSumm();
        jlGeneralSumm.setText("Общая сумма: " + summ);
    }//GEN-LAST:event_jbCreateSchemeActionPerformed

    private void jlBuyGodsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jlBuyGodsActionPerformed
        int state = canBuy();
        if (state == 0) {
            JOptionPane.showMessageDialog(this, "В городе недостаточно товара!", 
                "Ошибка", JOptionPane.ERROR_MESSAGE);
            return;
        }
        else if (state == -1) return;
        if (getGeneralSumm() > Start.inter.getTruck().getMoney()) {
            JOptionPane.showMessageDialog(this, "У вас не хватает денег!", 
                "Ошибка", JOptionPane.ERROR_MESSAGE);
            return;
        }
        God[] gods = Resources.gods;
        try
        {
            int count = Integer.parseInt(jtfGold.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[0], count, city);
            }
            count = Integer.parseInt(jtfTree.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[1], count, city);
            }
            count = Integer.parseInt(jtfCoal.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[2], count, city);
            }
            count = Integer.parseInt(jtfIron.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[3], count, city);
            }
            count = Integer.parseInt(jtfFood.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[4], count, city);
            }
            count = Integer.parseInt(jtfWater.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[5], count, city);
            }
            count = Integer.parseInt(jtfStone.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[6], count, city);
            }
            count = Integer.parseInt(jtfClothes.getText());
            if (count > 0) {
                Start.inter.getTruck().buyGod(gods[7], count, city);
            }
        }
        catch(Exception ex) { }
        finally {
            updateData();
            jlGeneralSumm.setText("Общая сумма: 0.0");
        }
    }//GEN-LAST:event_jlBuyGodsActionPerformed

    private void jbAcceptActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbAcceptActionPerformed
        int state = canSel();
        if (state == 0) {
            JOptionPane.showMessageDialog(this, "У вас недостаточно товара\n"
                    + " или городу столько не нужно!", 
                "Ошибка", JOptionPane.ERROR_MESSAGE);
            return;
        }
        else if (state == -1) return;
        double summ = getSelSumm();
        jlSumm.setText("Сумма сделки: " + summ);
    }//GEN-LAST:event_jbAcceptActionPerformed

    private void jbSelActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbSelActionPerformed
        int state = canSel();
        if (state == 0) {
            JOptionPane.showMessageDialog(this, "У вас недостаточно товара\n"
                    + " или городу столько не нужно!", 
                "Ошибка", JOptionPane.ERROR_MESSAGE);
            return;
        }
        else if (state == -1) return;
        int[] userWant = {
                Integer.parseInt(jtfGold2.getText()),
                Integer.parseInt(jtfTree2.getText()),
                Integer.parseInt(jtfCoal2.getText()),
                Integer.parseInt(jtfIron2.getText()),
                Integer.parseInt(jtfFood2.getText()),
                Integer.parseInt(jtfWater2.getText()),
                Integer.parseInt(jtfStone2.getText()),
                Integer.parseInt(jtfClothes2.getText())
            };
        for (int i = 0; i < userWant.length; i++) {
            if (userWant[i] != 0) {
                Start.inter.getTruck().selGod(Resources.gods[i], userWant[i], city);
            }
        }
        updateData();
        jlSumm.setText("Сумма сделки: 0.0");
    }//GEN-LAST:event_jbSelActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTabbedPane jTabbedPane;
    private javax.swing.JButton jbAccept;
    private javax.swing.JButton jbCreateScheme;
    private javax.swing.JButton jbSel;
    private javax.swing.JButton jlBuyGods;
    private javax.swing.JLabel jlCityClothes;
    private javax.swing.JLabel jlCityCoal;
    private javax.swing.JLabel jlCityFood;
    private javax.swing.JLabel jlCityGold;
    private javax.swing.JLabel jlCityHas;
    private javax.swing.JLabel jlCityIron;
    private javax.swing.JLabel jlCityStone;
    private javax.swing.JLabel jlCityTitle;
    private javax.swing.JLabel jlCityTree;
    private javax.swing.JLabel jlCityWater;
    private javax.swing.JLabel jlClothes;
    private javax.swing.JLabel jlClothes2;
    private javax.swing.JLabel jlClothesPrice;
    private javax.swing.JLabel jlClothesPrice2;
    private javax.swing.JLabel jlCoal;
    private javax.swing.JLabel jlCoal2;
    private javax.swing.JLabel jlCoalPrice;
    private javax.swing.JLabel jlCoalPrice2;
    private javax.swing.JLabel jlCount;
    private javax.swing.JLabel jlFood;
    private javax.swing.JLabel jlFood2;
    private javax.swing.JLabel jlFoodPrice;
    private javax.swing.JLabel jlFoodPrice2;
    private javax.swing.JLabel jlGeneralSumm;
    private javax.swing.JLabel jlGod2;
    private javax.swing.JLabel jlGold;
    private javax.swing.JLabel jlGold2;
    private javax.swing.JLabel jlGoldPrice;
    private javax.swing.JLabel jlGoldPrice2;
    private javax.swing.JLabel jlHasClothes;
    private javax.swing.JLabel jlHasCoal;
    private javax.swing.JLabel jlHasFood;
    private javax.swing.JLabel jlHasGods;
    private javax.swing.JLabel jlHasGold;
    private javax.swing.JLabel jlHasIron;
    private javax.swing.JLabel jlHasStone;
    private javax.swing.JLabel jlHasTree;
    private javax.swing.JLabel jlHasWater;
    private javax.swing.JLabel jlIron;
    private javax.swing.JLabel jlIron2;
    private javax.swing.JLabel jlIronPrice;
    private javax.swing.JLabel jlIronPrice2;
    private javax.swing.JLabel jlNeed;
    private javax.swing.JLabel jlNeedClothes;
    private javax.swing.JLabel jlNeedCoal;
    private javax.swing.JLabel jlNeedFood;
    private javax.swing.JLabel jlNeedGold;
    private javax.swing.JLabel jlNeedIron;
    private javax.swing.JLabel jlNeedStone;
    private javax.swing.JLabel jlNeedTree;
    private javax.swing.JLabel jlNeedWater;
    private javax.swing.JLabel jlPrice;
    private javax.swing.JLabel jlPrice2;
    private javax.swing.JLabel jlSelCount;
    private javax.swing.JLabel jlSelGod;
    private javax.swing.JLabel jlStone;
    private javax.swing.JLabel jlStone2;
    private javax.swing.JLabel jlStonePrice;
    private javax.swing.JLabel jlStonePrice2;
    private javax.swing.JLabel jlSumm;
    private javax.swing.JLabel jlTree;
    private javax.swing.JLabel jlTree2;
    private javax.swing.JLabel jlTreePrice;
    private javax.swing.JLabel jlTreePrice2;
    private javax.swing.JLabel jlTruckMoney;
    private javax.swing.JLabel jlWater;
    private javax.swing.JLabel jlWater2;
    private javax.swing.JLabel jlWaterPrice;
    private javax.swing.JLabel jlWaterPrice2;
    private javax.swing.JPanel jpBuy;
    private javax.swing.JPanel jpBuyGods;
    private javax.swing.JPanel jpSel;
    private javax.swing.JPanel jpSelGods;
    private javax.swing.JTextField jtfClothes;
    private javax.swing.JTextField jtfClothes2;
    private javax.swing.JTextField jtfCoal;
    private javax.swing.JTextField jtfCoal2;
    private javax.swing.JTextField jtfFood;
    private javax.swing.JTextField jtfFood2;
    private javax.swing.JTextField jtfGold;
    private javax.swing.JTextField jtfGold2;
    private javax.swing.JTextField jtfIron;
    private javax.swing.JTextField jtfIron2;
    private javax.swing.JTextField jtfStone;
    private javax.swing.JTextField jtfStone2;
    private javax.swing.JTextField jtfTree;
    private javax.swing.JTextField jtfTree2;
    private javax.swing.JTextField jtfWater;
    private javax.swing.JTextField jtfWater2;
    // End of variables declaration//GEN-END:variables
}
