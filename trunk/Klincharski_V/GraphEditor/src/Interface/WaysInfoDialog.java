

package Interface;

import Graph.*;

public class WaysInfoDialog extends javax.swing.JDialog {
    /** Мир */
    graph world;
    /** Номер первого пути в таблице */
    int startWay;

    /** Заполнение таблицы */
    private void fillWayTable() {
        int wayix = 0;
        for (edge way: world.getEdges()) {
            if (wayix < startWay) {
                wayix++;
                continue;
            }
            int row = wayix - startWay;
            if (row >= wayTable.getRowCount())
                break;
            wayTable.setValueAt(way.getVert1Name(), row, 0);
            wayTable.setValueAt(way.getVert2Name(), row, 1);
            wayTable.setValueAt(way.getEdgeKind().toString(), row, 2);
            wayTable.setValueAt(way.getDistance(), row, 3);
            wayTable.setValueAt(way.getFlag(), row, 4);
            wayix++;
        }
        jShownLabel.setText("Показаны пути с " + (startWay+1) +
                " по " + wayix + " из существующих " + world.getEdges().size());
    }

    /**
     * Инициализация таблицы
     */
    private void initWayTable() {
        startWay = 0;
        fillWayTable();
    }

    /**
     * Конструктор
     * @param parent родительский фрейм
     */
    public WaysInfoDialog(java.awt.Frame parent, boolean modal, graph world) {
        super(parent, modal);
        this.world = world;
        initComponents();
        initWayTable();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        wayTable = new javax.swing.JTable();
        next = new javax.swing.JButton();
        prev = new javax.swing.JButton();
        jShownLabel = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Существующие пути");

        wayTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null},
                {null, null, null, null, null}
            },
            new String [] {
                "Начало", "Конец", "Тип", "Стоимость", "Время"
            }
        ));
        wayTable.setName("wayTable"); // NOI18N
        jScrollPane1.setViewportView(wayTable);

        next.setText("Следующие");
        next.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                onNext(evt);
            }
        });

        prev.setText("Предыдущие");
        prev.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                onPrev(evt);
            }
        });

        jShownLabel.setText("jLabel1");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 375, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap(15, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 67, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jShownLabel)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(next)
                                .addGap(51, 51, 51)
                                .addComponent(prev)))
                        .addGap(76, 76, 76))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 63, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(17, 17, 17)
                .addComponent(jShownLabel)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(prev)
                    .addComponent(next))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Обработчик клавиши "Предыдущие"
     * @param evt событие
     */
    private void onPrev(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_onPrev
        // TODO add your handling code here:
        if (startWay==0)
            return;
        startWay -= wayTable.getRowCount();
        if (startWay < 0)
            startWay = 0;
        fillWayTable();
    }//GEN-LAST:event_onPrev
    /**
     * Обработчик клавиши "Следующие"
     * @param evt событие
     */
    private void onNext(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_onNext
        // TODO add your handling code here:
        if (startWay + wayTable.getRowCount() >= world.getEdges().size())
            return;
        startWay += wayTable.getRowCount();
        fillWayTable();
    }//GEN-LAST:event_onNext

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel jShownLabel;
    private javax.swing.JButton next;
    private javax.swing.JButton prev;
    private javax.swing.JTable wayTable;
    // End of variables declaration//GEN-END:variables

}