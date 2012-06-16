/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Customer_shop;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextField;
import javax.swing.JTree;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;

/**
 *
 * @author Mit
 */
@SuppressWarnings("all")
public class CustomerMS extends JFrame implements ActionListener, TreeSelectionListener, ListSelectionListener{
    private final String DB_NAME="lib1.db";
    private DefaultMutableTreeNode root;
    private DefaultTreeModel treeModel;
    private JTree tree;

    private DefaultListModel dlmCus;
    private JList lstCus;

    private JTextField tfID,tfName,tfAddress,tfPhone;
    private JButton btAdd,btSave,btRepair,btDelete;
    private JButton btAddTypeCus,btRemTypeCus;

    private ListCustomer db=null;//dùng nạp toàn bộ csdl
    private TypeCustomer selTypeCus=null;

    public CustomerMS() {
        super("BOOK SHOP");
        addWindowListener(new WindowAdapter(){
        @Override
        public void windowClosing(WindowEvent arg0) {
        //lưu csdl
        SaveDB();
        //thoat
        this.windowClosed(arg0);
        }
        });
        setSize(600,400);
        TaoHeader();
        TaoGUI();
        LoadDB();
        /*db.AddShelf(new Shelf(“s01″,”Tiểu thuyết 3 xu”));
        db.AddShelf(new Shelf(“s02″,”Sách Tin học”));
        db.AddShelf(new Shelf(“s03″,”Sách Ngoại ngữ”));*/
        LockText(true);//không cho sửa
        }
    /**
    * Hàm này thực thi khi bắt đầu chạy chương trình
    */
    void LoadDB(){
        try {
            if(!new File(DB_NAME).exists()){//chưa tồn tại csdl
                db=new ListCustomer("bien hoa","room001");
                }
            else{
                database2 b=new database2();
                db=(ListCustomer)b.DeserialObject(DB_NAME);
                //xây dựng tree
                BuildTree();
                }
        } 
        catch (Exception e) {
            //JOptionPane.showMessageDialog(null, "Error database");
        }
        }
    /**
    * Xây dựng tree dựa trên DB
    */
    void BuildTree() {
        root.removeAllChildren();
        for (int i = 0; i < db.Count(); i++) {
            TypeCustomer sf=db.getTypeCus(i);
            root.add(new DefaultMutableTreeNode(sf));
        }
        tree.updateUI();//cập nhật lên jtree
        }
    /**
    * Chạy khi kết chương trình
    * dùng để update dữ liệu xuống file
    */
    void SaveDB(){
        try {
            new database2().SerialObject(db, DB_NAME);
        } 
        catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Error save database");
        }
        }

    void TaoHeader(){
        JLabel lbl=new JLabel("BOOK SHOP MANAGMENT SYSTEM           Customer",JLabel.CENTER);
        lbl.setFont(new Font("Arial",Font.BOLD,30));
        lbl.setForeground(Color.blue);
        this.add(lbl,BorderLayout.NORTH);
        }
    void TaoGUI(){

    //tạo tree
    root=new DefaultMutableTreeNode("List Customer");        //re cay
    treeModel=new DefaultTreeModel(root);
    tree=new JTree(treeModel);
    tree.addTreeSelectionListener(this);
    JScrollPane treePane=new JScrollPane(tree);             //cuon

    JPanel pLeft=new JPanel(new BorderLayout());
    pLeft.add(treePane,BorderLayout.CENTER);
    JPanel pFunc=new JPanel();
    pFunc.add(btAddTypeCus=new JButton("Add TypeCus"));
    pFunc.add(btRemTypeCus=new JButton("Remove TypeCus"));
    btAddTypeCus.addActionListener(this);
    btRemTypeCus.addActionListener(this);
    pLeft.add(pFunc,BorderLayout.SOUTH);

    JPanel pCen=new JPanel(new BorderLayout());
    JSplitPane spPane=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,pLeft,pCen);       //duong phan chia
    this.add(spPane,BorderLayout.CENTER);

    //Pane details
    JPanel pList=new JPanel(new BorderLayout());
    JPanel pDetails=new JPanel(new BorderLayout());

    pList.setBorder(BorderFactory.createTitledBorder("Customer listing…"));
    pDetails.setBorder(BorderFactory.createTitledBorder("Selected customer informations"));

    pCen.add(pList,BorderLayout.CENTER);
    pCen.add(pDetails,BorderLayout.SOUTH);
    //Them list book
    dlmCus=new DefaultListModel();
    lstCus=new JList(dlmCus);
    pList.add(new JScrollPane(lstCus));
    lstCus.setPreferredSize(new Dimension(200,200));
    lstCus.addListSelectionListener(this);

    //tạo details
    Box b=Box.createVerticalBox();
    Box b1=Box.createHorizontalBox();
    Box b2=Box.createHorizontalBox();
    Box b3=Box.createHorizontalBox();
    Box b4=Box.createHorizontalBox();
    Box b5=Box.createHorizontalBox();
    Box b6=Box.createHorizontalBox();

    b.add(b1);b.add(Box.createVerticalStrut(7));
    b.add(b2);b.add(Box.createVerticalStrut(7));
    b.add(b3);b.add(Box.createVerticalStrut(7));
    b.add(b4);b.add(Box.createVerticalStrut(7));
    b.add(b5);b.add(Box.createVerticalStrut(7));
    b.add(b6);b.add(Box.createVerticalStrut(7));

    JLabel l1,l2,l3,l4,l5;
    b1.add(l1=new JLabel("Customer ID ",JLabel.RIGHT));b1.add(tfID=new JTextField(20));
    b2.add(l2=new JLabel("Name ",JLabel.RIGHT));b2.add(tfName=new JTextField(20));
    b3.add(l3=new JLabel("Address ",JLabel.RIGHT));b3.add(tfAddress=new JTextField(20));
    b4.add(l4=new JLabel("Phone ",JLabel.RIGHT));b4.add(tfPhone=new JTextField(20));

    l4.setPreferredSize(l1.getPreferredSize());                                             //de trung do da`i cua cac o
    l2.setPreferredSize(l1.getPreferredSize());
    l3.setPreferredSize(l1.getPreferredSize());

    b6.add(btAdd=new JButton("Add"));btAdd.addActionListener(this);
    b6.add(btSave=new JButton("Save"));btSave.addActionListener(this);btSave.setEnabled(false);     //false la ko hien len
    b6.add(btRepair=new JButton("Repair"));btRepair.addActionListener(this);
    b6.add(btDelete=new JButton("Delete"));btDelete.addActionListener(this);
    pDetails.add(b,BorderLayout.CENTER);
    }

    private void LockText(boolean status){
    tfID.setEditable(!status);
    tfPhone.setEditable(!status);
    tfName.setEditable(!status);
    tfID.setEditable(!status);
    tfAddress.setEditable(!status);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
    Object o=e.getSource();
    if(o.equals(btAddTypeCus)) {
        String sID=JOptionPane.showInputDialog("Input ID of TypeCus");                    //JOption dung de hien len TEXT trong bang nho
        String sName=JOptionPane.showInputDialog("Input name of TypeCus");
        if(sID==null||sName==null)
            return;
        if(sID.trim().equals("")||sName.trim().equals("")) {
            JOptionPane.showMessageDialog(null, "Input ID and Name of TypeCus");
            return;
            }
        TypeCustomer sf=new TypeCustomer(sID,sName);
        if(db.AddType(sf)) {                                                       //neu them duoc sach thi cho vao cay luon
            BuildTree();
            }
        else
        JOptionPane.showMessageDialog(null, "Cannot add this TypeCus!");
        }
    
    else if(o.equals(btRemTypeCus)) {
        try {
//            if(selTypeCus==null) {
//                JOptionPane.showMessageDialog(null, "Choose TypeCus of book");
//                return;
//                }
//            if(JOptionPane.showConfirmDialog(null,
//            "You sure delete?",
//            "OK",JOptionPane.YES_NO_OPTION,
//            JOptionPane.QUESTION_MESSAGE)==JOptionPane.YES_OPTION) {
//            DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
//            root.remove(selNode);
//            if(db.RemoveTypeCus(selTypeCus.getTypeID()))
//                BuildTree();
//            }
        DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
           String []tem=selNode.toString().split(" ");
           treeModel.removeNodeFromParent(selNode);
            //delete trog du lieu db nua
            for(int i=0;i<db.getTypeCusList().size();i++)
            {
            if(db.getTypeCusList().get(i).getTypeID()==tem[0])
            {
                db.getTypeCusList().remove(i);
                break;
            }
            }
            tree.updateUI();
        
        }
        catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "Can not delete");
            System.out.println(ex);
            }
        }
    
    else if(o.equals(btAdd)){
        if(btAdd.getText().equalsIgnoreCase("Add")){
            btAdd.setText("Cancel");                       //chuyen tu them->huy bo
            btSave.setEnabled(true);
            btDelete.setEnabled(false);
            btRepair.setEnabled(false);
            LockText(false);
            }
        else{
            btAdd.setText("Add");                         //chuyen tu huy bo->them
            btSave.setEnabled(false);
            btDelete.setEnabled(true);
            btRepair.setEnabled(true);
            LockText(true);
            }
        }
    
    else if(o.equals(btSave)){
        if(tfID.getText().trim().equals("")||                       //1 trong ca'c chi so con thieu-> phai nhap het
        tfName.getText().trim().equals("")||
        tfAddress.getText().trim().equals("")||
        tfPhone.getText().trim().equals("")){
            JOptionPane.showMessageDialog(null, "is not space!! ");
            return;
            }
//------------------------------------- 
        
        if(btAdd.isEnabled()){                                                         //nút lưu của nút thêm
            DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
            String []tem=selNode.toString().split(" ");
            String IDShelf=tem[0];
            Customer b=new Customer(tfID.getText(),tfName.getText(),
            tfAddress.getText(), tfPhone.getText());
            
            for(int i=0;i<db.getTypeCusList().size();i++)
            {
            if(db.getTypeCusList().get(i).getTypeID()==IDShelf)
            db.getTypeCusList().get(i).AddCus(b);
            }
            
                    dlmCus.addElement(b);
                    //khôi phục tình trạng
                    btAdd.setText("Add");
                    btSave.setEnabled(false);
                    btDelete.setEnabled(true);
                    btRepair.setEnabled(true);
                    LockText(true);
                    }
           else{                                                                           //nút lưu là của nút sửa
            if(selTypeCus!=null) {
                Customer b=new Customer(tfID.getText(),tfName.getText(),
                tfAddress.getText(),tfPhone.getText());
                if(!selTypeCus.UpdateCusInfos(tfID.getText(), b))
                    JOptionPane.showMessageDialog(null, "Cannot update");
                else {
                    //BuildList();
                    btRepair.setText("Repair");
                    btSave.setEnabled(false);
                    btDelete.setEnabled(true);
                    btAdd.setEnabled(true);
                    LockText(true);
                    lstCus.setEnabled(true);
                    tree.setEnabled(true);
                    }
                }
            else
            JOptionPane.showMessageDialog(null, "Cannot update. Choose shelf");
            }
        }
    else if(o.equals(btRepair)) {
        if(tfID.getText().trim().equals("")) {
            JOptionPane.showMessageDialog(null, "Choose customer (repair information)");
            return;
            }
        if(btRepair.getText().equalsIgnoreCase("Repair")){
            btRepair.setText("Cancel");
            btSave.setEnabled(true);
            btDelete.setEnabled(false);
            btAdd.setEnabled(false);
            LockText(false);
            tfID.setEditable(false);
            lstCus.setEnabled(false);
            tree.setEnabled(false);
            }
        else{
            btRepair.setText("Repair");
            btSave.setEnabled(false);
            btDelete.setEnabled(true);
            btAdd.setEnabled(true);
            LockText(true);
            lstCus.setEnabled(true);
            tree.setEnabled(true);
            }
        }
    
    else if(o.equals(btDelete)) {
        String id=tfID.getText();
        if(id.trim().equals("")) {
            JOptionPane.showMessageDialog(null, "Choose customer");
            return;
            }
        if(JOptionPane.showConfirmDialog(null,
        "You sure delete?",
        "OK",JOptionPane.YES_NO_OPTION,
        JOptionPane.QUESTION_MESSAGE)==JOptionPane.YES_OPTION) {

            if(!selTypeCus.RemoveCus(id))
                JOptionPane.showMessageDialog(null, "Cannot delete!");
            else {
                //BuildList();
                }
            }
        }
    }
    
    //khi chọn lên tree sẽ liệt kê các sách của kệ đang chọn
    @Override
    public void valueChanged(TreeSelectionEvent te) {
    
        try {
            DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
            if(selNode.getLevel()>0) {
                selTypeCus=(TypeCustomer)selNode.getUserObject();
                //đưa danh sách các cus vào list
                BuildList();
                }
            } 
            catch (Exception e) {
                System.out.println(e.getMessage());
                }
    }

    private void BuildList() {
        dlmCus.clear();
        for (int i = 0; i < selTypeCus.Count(); i++) {
            Customer b=selTypeCus.GetCus(i);
            dlmCus.addElement(b);
            }
        }
    //Khi chọn lên 1 cuốn sách trong jlist
    //sẽ hiển thị thông tin chi tiết trên các textfield
    @Override
    public void valueChanged(ListSelectionEvent arg0) {
    
        try {
            Customer selBook=(Customer)lstCus.getSelectedValue();
            if(selBook!=null) {
                tfID.setText(selBook.getCusID());
                tfName.setText(selBook.getCusName());
                tfAddress.setText(selBook.getCusAddress());
                tfPhone.setText(selBook.getCusPhone());
                }
            } 
        catch (Exception e) {
    e.printStackTrace();
    }
    }
    
    
    @Override
    public String toString(){
        return "";
    }
    
    public String FindKeyOfList()
    {
         DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
         String []tem=selNode.toString().split(" ");
         return tem[0];
    }
}
