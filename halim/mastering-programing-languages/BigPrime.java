import java.math.*;
import java.util.Scanner;

public class BigPrime {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    String s = in.nextLine();
    BigInteger x = new BigInteger(s);
    System.out.println(x.isProbablePrime(10) ? "Prime" : "Composite");
  }
}
