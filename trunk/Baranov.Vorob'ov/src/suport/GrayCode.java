package suport;

public class GrayCode {

    public static int encodeGray(int natural) {

        return natural ^ natural >>> 1;

    }
    
    public static String encodeGray(int natural, int s) {

        String num = Integer.toBinaryString(natural ^ natural >>> 1);
        String zer = "";
        for(int i = 0; i<(s-num.length()); i++)
        {
            zer+="0";
        }
        
        return zer+=num;

    }
    
    public static int decodeGray(int gray) {

        int natural = 0;

        while (gray != 0) {

            natural ^= gray;

            gray >>>= 1;

        }

        return natural;

    }
}
