public class rle {

    public static void main(String[] args) {
        String str = "AAABBBCCCDDD";
        int count = 0;
        String result = "";
        for(int i = 0; i< str.length(); i++){

            if (i == 0) {
                result = result+str.charAt(i);
                count++;
            }
            if(i !=0 && str.charAt(i) == str.charAt(i-1)){
                count ++;
            }
            else if(i !=0 && str.charAt(i) != str.charAt(i-1)){

                result = result+count+str.charAt(i);
                count = 1;
            }

            if(i == str.length()-1){
                result = result+count;
            }

        }
        System.out.println(str);
        System.out.println(result);


    }
    
}
