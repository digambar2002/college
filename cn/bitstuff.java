import java.util.Scanner;

public class bitstuff {

    public static void main(String[] args) {
        String str = "";
        String bitStuff = "";
        String bitUnStuff = "";
        int count = 0;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter String");
        str = sc.nextLine();

        for(int i = 0; i<str.length(); i++){


            if(str.charAt(i) == '1'){
                count++;
            }
            else{
                count = 0;
            }

            if (count == 5) {
                count =0;
                bitStuff = bitStuff+'0';
            }
            
            bitStuff = bitStuff+str.charAt(i);
            
        }

        System.out.println("Bit stuffed");
        System.out.println(bitStuff);

        
        // here out input string is bitstuffed
        bitUnStuff = str;
        System.out.println("");
        System.out.println("Bit unstuffed");
        System.out.println(bitUnStuff);


    }
}