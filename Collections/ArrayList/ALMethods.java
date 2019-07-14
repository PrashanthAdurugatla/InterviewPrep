import java.util.*;

public class ALMethods
{
  public static void main (String[]args)
  {
    String [] str1 = {"CA","AZ","TX","AL","AZ","CA","CO","CT","DE","FL","GA"};
    String [] str2 = {"DE","CO","CA","PA"};
    
    ArrayList < String > al = new ArrayList < String > ();
        for(String i: str1)
            al.add(i);
            
    ArrayList < String > common = new ArrayList < String > ();
        for(String i: str2)
            al.add(i);
    
    al.remove("CA");
    System.out.println (al);
    
    int i = al.indexOf("CA");
    System.out.println (i);
    
    String s = al.get(i);
    System.out.println (s);
    
    al.set(4, "GA");
    System.out.println (al);
    
    common.retainAll(al);
     System.out.println (common);
    
  }

}
