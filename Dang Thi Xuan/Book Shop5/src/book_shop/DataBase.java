///*
// * To change this template, choose Tools | Templates
// * and open the template in the editor.
// */
//package book_shop;
//import java.io.*;
//
///**
// *
// * @author Mit
// */
//
//
//public class DataBase {
//    
//    public void SerialObject(LibRoom obj,String outFile)throws Exception{
//           // PrintWriter out = new PrintWriter(outFile);
//             FileWriter fstream = new FileWriter(outFile,true);
//            BufferedWriter out = new BufferedWriter(fstream);
//            Book tempBook=null;
//            for(int i=0;i<=obj.getShelfList().size();i++)
//            {
//                out.write(obj.getShelfList().get(i).getShelfID()+"  "+obj.getShelfList().get(i).getShelfName()+" \n");
//                tempBook=obj.getShelfList().get(i).getListBook().get(i);
//                if(tempBook!=null)
//                out.write(tempBook.getBookID()+"  "+tempBook.getBookTitle()+"  "
//                        +tempBook.getAuthorName()+"  "+String.valueOf(tempBook.getPrice())+
//                        "  "+String.valueOf(tempBook.getNoPages())+" \n");
//            }
//            out.close();
//        }
//
//    public LibRoom DeserialObject(String inFile)throws Exception{
//            BufferedReader in = new BufferedReader(new FileReader(inFile));
//            LibRoom obj=null;
//            String line;
//            String temL=null;
//            String[] t1;
//         
//            Shelf tempSheft=null;
//            Book tempBook=null;
//            line=in.readLine();
//            t1=line.split("  ");
//            tempSheft.setShelfID(t1[0]);
//            tempSheft.setShelfName(t1[1]);
//            while((line=in.readLine())!=null)
//            {
//                t1=line.split("  ");
//                if(line.length()<4)
//                {
//                    tempBook=null;
//                    tempSheft.getListBook().add(tempBook);
//                    tempSheft.setShelfID(t1[0]);
//                    tempSheft.setShelfName(t1[1]);
//                    temL=line;
//                
//                }else{
//                tempBook.setBookID(t1[0]);
//                tempBook.setAuthorName(t1[2]);
//                tempBook.setBookTitle(t1[1]);
//                tempBook.setNoPages(Double.parseDouble(t1[3]));
//                tempBook.setNoPages(Integer.parseInt(t1[4]));
//                tempSheft.getListBook().add(tempBook);
//                obj.getShelfList().add(tempSheft);
//                }
//                
//              //  obj.getShelfList().add(tempSheft);
//            }
//            if(temL.length()<4)
//            {
//                tempBook=null;
//                tempSheft.getListBook().add(tempBook);
//            }
//             in.close();
//            return obj;
//        }
//    }
