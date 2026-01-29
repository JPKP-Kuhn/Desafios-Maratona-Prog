import java.util.Scanner;
import java.math.BigInteger;

public class ConvertBase {
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    String num = in.nextLine();
    int x = in.nextInt();
    int y = in.nextInt();
    System.out.println(new BigInteger(num, x).toString(y));
  }
}
