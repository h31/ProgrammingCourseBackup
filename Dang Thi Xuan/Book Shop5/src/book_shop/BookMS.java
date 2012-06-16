/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package book_shop;
//import Customer_shop.database2;
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
//import javax.swing.tree.TreePath;

//import quanlysach.Book;
//import quanlysach.Shelf;
//import quanlysach.LibRoom;
//import quanlysach.Database;

/**
 *
 * @author Mit
 */


@SuppressWarnings("all")
public class BookMS extends JFrame implements ActionListener, TreeSelectionListener, ListSelectionListener{
    private final String DB_NAME="lib.txt";
    private DefaultMutableTreeNode root;
    private DefaultTreeModel treeModel;
    private JTree tree;

    private DefaultListModel dlmBook;
    private JList lstBook;

    private JTextField tfID,tfTitle,tfAuthor,tfPages,tfPrice;
    private JButton btAdd,btSave,btRepair,btDelete;
    private JButton btAddShelf,btRemShelf;

    private LibRoom db=null;//dùng nạp toàn bộ csdl
    private Shelf selShelf=null;

    
    public BookMS() {
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
                db=new LibRoom("bien hoa","room001");
                }
            else{
                database1 b=new database1();
                db=(LibRoom)b.DeserialObject(DB_NAME);
                //xây dựng tree
                BuildTree();
                }
        } 
        catch (Exception e) {
           // System.out.printf(e.getMessage());
        }
        }
    /**
    * Xây dựng tree dựa trên DB
    */
    void BuildTree() {
        root.removeAllChildren();
        for (int i = 0; i < db.Count(); i++) {
            Shelf sf=db.getShelf(i);
            root.add(new DefaultMutableTreeNode(sf.toString()));
        }
        tree.updateUI();//cập nhật lên jtree
        }
    /**
    * Chạy khi kết chương trình
    * dùng để update dữ liệu xuống file
    */
    void SaveDB(){
        try {
            new database1().SerialObject(db, DB_NAME);
        } 
        catch (Exception e) {
            //JOptionPane.showMessageDialog(null, "Error save database");
        }
        }

    void TaoHeader(){
        JLabel lbl=new JLabel("BOOK SHOP MANAGMENT SYSTEM",JLabel.CENTER);
        lbl.setFont(new Font("Arial",Font.BOLD,30));
        lbl.setForeground(Color.blue);
        this.add(lbl,BorderLayout.NORTH);
        }
    void TaoGUI(){

        
        
    //tạo tree
    root=new DefaultMutableTreeNode("List Shelf");        //re cay
    treeModel=new DefaultTreeModel(root);
    tree=new JTree(treeModel);
    tree.addTreeSelectionListener(this);
    JScrollPane treePane=new JScrollPane(tree);             //cuon

    JPanel pLeft=new JPanel(new BorderLayout());
    pLeft.add(treePane,BorderLayout.CENTER);
    JPanel pFunc=new JPanel();
    pFunc.add(btAddShelf=new JButton("Add Shelf"));
    pFunc.add(btRemShelf=new JButton("Remove Shelf"));
    btAddShelf.addActionListener(this);
    btRemShelf.addActionListener(this);
    pLeft.add(pFunc,BorderLayout.SOUTH);

    JPanel pCen=new JPanel(new BorderLayout());
    JSplitPane spPane=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,pLeft,pCen);       //duong phan chia
    this.add(spPane,BorderLayout.CENTER);

    //Pane details
    JPanel pList=new JPanel(new BorderLayout());
    JPanel pDetails=new JPanel(new BorderLayout());

    pList.setBorder(BorderFactory.createTitledBorder("Book listing…"));
    pDetails.setBorder(BorderFactory.createTitledBorder("Selected book informations"));

    pCen.add(pList,BorderLayout.CENTER);
    pCen.add(pDetails,BorderLayout.SOUTH);
    //Them list book
    dlmBook=new DefaultListModel();
    lstBook=new JList(dlmBook);
    pList.add(new JScrollPane(lstBook));
    lstBook.setPreferredSize(new Dimension(200,200));
    lstBook.addListSelectionListener(this);

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
    b1.add(l1=new JLabel("Book ID ",JLabel.RIGHT));b1.add(tfID=new JTextField(20));
    b2.add(l2=new JLabel("Title ",JLabel.RIGHT));b2.add(tfTitle=new JTextField(20));
    b3.add(l3=new JLabel("Author ",JLabel.RIGHT));b3.add(tfAuthor=new JTextField(20));
    b4.add(l4=new JLabel("No. Pages ",JLabel.RIGHT));b4.add(tfPages=new JTextField(20));
    b5.add(l5=new JLabel("Price ",JLabel.RIGHT));b5.add(tfPrice=new JTextField(20));

    l1.setPreferredSize(l4.getPreferredSize());                                             //de trung do da`i cua cac o
    l2.setPreferredSize(l4.getPreferredSize());
    l3.setPreferredSize(l4.getPreferredSize());
    l5.setPreferredSize(l4.getPreferredSize());

    b6.add(btAdd=new JButton("Add"));btAdd.addActionListener(this);
    b6.add(btSave=new JButton("Save"));btSave.addActionListener(this);btSave.setEnabled(false);     //false la ko hien len
    b6.add(btRepair=new JButton("Repair"));btRepair.addActionListener(this);
    b6.add(btDelete=new JButton("Delete"));btDelete.addActionListener(this);
    pDetails.add(b,BorderLayout.CENTER);
    }

    private void LockText(boolean status){
    tfID.setEditable(!status);
    tfPages.setEditable(!status);
    tfPrice.setEditable(!status);
    tfTitle.setEditable(!status);
    tfAuthor.setEditable(!status);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
    Object o=e.getSource();
    if(o.equals(btAddShelf)) {
        String sID=JOptionPane.showInputDialog("Input ID of Shelf");                    //JOption dung de hien len TEXT trong bang nho
        String sName=JOptionPane.showInputDialog("Input name of Shelf");
        if(sID==null||sName==null)
            return;
        if(sID.trim().equals("")||sName.trim().equals("")) {
            JOptionPane.showMessageDialog(null, "Input ID and Name of shelf");
            return;
            }
        Shelf sf=new Shelf(sID,sName);
        if(db.AddShelf(sf)) {                                                       //neu them duoc sach thi cho vao cay luon
            BuildTree();
            }
        else
        JOptionPane.showMessageDialog(null, "Cannot add this shelf!");
        }
    
    else if(o.equals(btRemShelf)) {
        try {
//             DefaultMutableTreeNode node;
//            DefaultTreeModel model = (DefaultTreeModel) (tree.getModel());
//            TreePath[] paths = tree.getSelectionPaths();
//            if(paths==null)
//            {
//                JOptionPane.showMessageDialog(null, "Choose shelf of book");
//                return;
//            }
//            else if (JOptionPane.showConfirmDialog(null,
//            "Are you sure to delete this shelf of book?",
//            "OK",JOptionPane.YES_NO_OPTION,
//            JOptionPane.QUESTION_MESSAGE)==JOptionPane.YES_OPTION) 
//            
//           
//            for (int i = 0; i < paths.length; i++) {
//             node = (DefaultMutableTreeNode) (paths[i].getLastPathComponent());
//             model.removeNodeFromParent(node);
       // }
          DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
           String []tem=selNode.toString().split(" ");
           treeModel.removeNodeFromParent(selNode);
            //delete trog du lieu db nua
            for(int i=0;i<db.getShelfList().size();i++)
            {
            if(db.getShelfList().get(i).getShelfID()==tem[0])
            {
                db.getShelfList().remove(i);
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
        tfTitle.getText().trim().equals("")||
        tfAuthor.getText().trim().equals("")||
        tfPrice.getText().trim().equals("")||
        tfPages.getText().trim().equals("")){
            JOptionPane.showMessageDialog(null, "is not space!! ");
            return;
            }
        int pages=0;
        try {
            pages = Integer.parseInt(tfPages.getText());
            } 
        catch (Exception e1) {
            JOptionPane.showMessageDialog(null, "Input integer of pages ");
            tfPages.selectAll();tfPages.requestFocus();
            return;
            }
//------------------------------------- 
        double price=0.0;
        try {
            price = Double.parseDouble(tfPrice.getText());
            } 
        catch (Exception e1) {
            JOptionPane.showMessageDialog(null, "Input double of price's book ");
            tfPrice.selectAll();tfPrice.requestFocus();
            return;
            }
        if(btAdd.isEnabled()){                                     //nút lưu của nút thêm
            DefaultMutableTreeNode selNode=(DefaultMutableTreeNode)tree.getSelectionPath().getLastPathComponent();
            String []tem=selNode.toString().split(" ");
            String IDShelf=tem[0];
            Book b=new Book(tfID.getText(),tfTitle.getText(),
            tfAuthor.getText(), price, pages);
         
          for(int i=0;i<db.getShelfList().size();i++)
            {
            if(db.getShelfList().get(i).getShelfID()==IDShelf)
            db.getShelfList().get(i).AddBook(b);
            }
      
            dlmBook.addElement(b.toString());
            //khôi phục tình trạng
            btAdd.setText("Add");
            btSave.setEnabled(false);
            btDelete.setEnabled(true);
            btRepair.setEnabled(true);
            LockText(true);

            }
        else{                                                                           //nút lưu là của nút sửa
            if(selShelf!=null) {
                Book b=new Book(tfID.getText(),tfTitle.getText(),
                tfAuthor.getText(),Double.parseDouble(tfPrice.getText()),Integer.parseInt(tfPages.getText()));
                if(!selShelf.UpdateBookInfos(tfID.getText(), b))
                    JOptionPane.showMessageDialog(null, "Cannot update");
                else {
                    //BuildList();
                    btRepair.setText("Repair");
                    btSave.setEnabled(false);
                    btDelete.setEnabled(true);
                    btAdd.setEnabled(true);
                    LockText(true);
                    lstBook.setEnabled(true);
                    tree.setEnabled(true);
                    }
                }
            else
            JOptionPane.showMessageDialog(null, "Cannot update. Choose shelf");
            }
        }
    else if(o.equals(btRepair)) {
        if(tfID.getText().trim().equals("")) {
            JOptionPane.showMessageDialog(null, "Choose book (repair information)");
            return;
            }
        if(btRepair.getText().equalsIgnoreCase("Repair")){
            btRepair.setText("Cancel");
            btSave.setEnabled(true);
            btDelete.setEnabled(false);
            btAdd.setEnabled(false);
            LockText(false);
            tfID.setEditable(false);
            lstBook.setEnabled(false);
            tree.setEnabled(false);
            }
        else{
            btRepair.setText("Repair");
            btSave.setEnabled(false);
            btDelete.setEnabled(true);
            btAdd.setEnabled(true);
            LockText(true);
            lstBook.setEnabled(true);
            tree.setEnabled(true);
            }
        }
    
    else if(o.equals(btDelete)) {
        String id=tfID.getText();
        if(id.trim().equals("")) {
            JOptionPane.showMessageDialog(null, "Choose book");
            return;
            }
        if(JOptionPane.showConfirmDialog(null,
        "Bạn chắc chắn xóa cuốn sách này chứ?",
        "OK",JOptionPane.YES_NO_OPTION,
        JOptionPane.QUESTION_MESSAGE)==JOptionPane.YES_OPTION) {

            if(!selShelf.RemoveBook(id))
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
                selShelf=(Shelf)selNode.getUserObject();
                //đưa danh sách các book vào list
                BuildList();
                }
            } 
            catch (Exception e) {
                System.out.println(e.getMessage());
                }
    }

    private void BuildList() {
        dlmBook.clear();
        for (int i = 0; i < selShelf.Count(); i++) {
            Book b=selShelf.GetBook(i);
            dlmBook.addElement(b);
            }
        //dlmBook.removeAllElements();
        //tim vi tri cua shelf kich chuot vao
//         String IDShelf=FindKeyOfList();
//         for(int i=0;i<db.getShelfList().size();i++)
//            {
//            if(db.getShelfList().get(i).getShelfID()==IDShelf)
//            {
//                for (int j = 0; j < db.getShelfList().get(i).getListBook().size(); i++) 
//                {
//                    Book b=db.getShelfList().get(i).getListBook().get(j);
//                    dlmBook.addElement(b);
//                }
//                break;
//            }
//           
//            }
  
        }
    //Khi chọn lên 1 cuốn sách trong jlist
    //sẽ hiển thị thông tin chi tiết trên các textfield
    @Override
    public void valueChanged(ListSelectionEvent arg0) {
    
        try {
            Book selBook=(Book)lstBook.getSelectedValue();
            if(selBook!=null) {
                tfID.setText(selBook.getBookID());
                tfTitle.setText(selBook.getBookTitle());
                tfAuthor.setText(selBook.getAuthorName());
                tfPrice.setText(selBook.getPrice()+"");
                tfPages.setText(selBook.getNoPages()+"");
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
//exit(lib.txt);
}
