package suport;

public class GrayCode {

    public static int encodeGray(int natural) {

        return natural ^ natural >>> 1;

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
