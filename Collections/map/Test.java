import java.util.*;

class Test {
  public static void main(String[] args) {


    Map<String, String> map = new HashMap<>();

    map.put("name", "Prashanth");
    map.put("city", "hayward");
    map.put("city", "SFO");
    map.put("state", "Ca");
    
    Set<String> keys = map.keySet();

    for(String key:keys)
    System.out.println(key+"-->"+map.get(key));
  }
}
