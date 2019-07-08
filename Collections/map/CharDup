import java.util.*;

class CharDup {
  public static void main(String[] args) {
    
    String str = "Prashanth";

  Map<Character, Integer> map = new HashMap<>();

  for(int i=0; i<str.length(); i++){

    char c = str.charAt(i);

    if(map.get(c)== null)
      map.put(c, 1);
    else
      map.put(c, map.get(c)+1);
  }


  Iterator<Character> c = map.keySet().iterator();
  while(c.hasNext()){
    Character temp = c.next();
    if(map.get(temp)>1)
    System.out.println(temp + "-->" + map.get(temp));
  }


  }

  
}
