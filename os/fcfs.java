import java.util.Scanner;

/**
 * fcfs
 */
public class fcfs {

    public static void main(String[] args) {
        int n, avwt = 0, avtat=0, i, j;
        int[] wt = new int [20];
        int[] bt = new int [20];
        int [] tat = new int[20];
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter total number of processes(maximum 20):");
        n = sc.nextInt();
        // System.out.println(n);

        for(i=0; i < n; i++ ){

            System.out.println("P["+(i)+"]");
            bt[i] = sc.nextInt();

        }

        for(i=0; i < n; i++ ){

            System.out.println("P["+(i)+"]: "+bt[i]);
           

        }


    }
}