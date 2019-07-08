import java.util.*;
class StringDup {
  public static void main(String[] args) {
    
    String str = "I Love to Love Java Java";
    String [] S = str.split(" ");

    
    Map<String, Integer> map = new HashMap<>();

    for(String tempString : S){
    if(map.get(tempString)!=null) {
      map.put(tempString, map.get(tempString)+1);
    }else{
       map.put(tempString, 1);
    }
    }

    Iterator<String> tempString = map.keySet().iterator();
    while(tempString.hasNext()){

      String temp = tempString.next();
      if(map.get(temp)>1)
        System.out.println(temp + "--->" + map.get(temp));
      
    }
  
   System.out.println(map);
   

  }

}
