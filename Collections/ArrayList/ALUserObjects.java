import java.util.*;
class Employee{
    public String name;
    public int id;
    public String address;
    
    Employee(String name, int id, String address){
        this.name = name;
        this.id = id;
        this.address = address;
    }
    
    public String getName(){
        return name;
    }
}
public class ALUserObjects
{
	public static void main(String[] args) {
	    
	    Employee e1 = new Employee("Prashanth", 111, "CA");
	    Employee e2 = new Employee("John", 222, "AZ");
	    Employee e3 = new Employee("Smith", 333, "TX");
	    
	    //Storing User Defined Class objects in ArrayList
	    ArrayList<Employee> al = new ArrayList<>();
	    //Adding user defined objects in ArrayList object
	    al.add(e1);
	    al.add(e2);
	    al.add(e3);
	    
	   
	    //Finding an Object in ArrayList using NAME Property
	   
	    for(Employee e : al){
	        if(e.name.equals("Prashanth")){
	            System.out.println(e.name + "--" + e.id + "--" + e.address);
	           // al.remove(e);
	        }
	    }     
	    
	    
	    //use Iterator method on ArrayList object (a1.Iterator()) and it returns an reference 
	    
	    Iterator<Employee> it = al.iterator();
	    while(it.hasNext()){
	        Employee emp = it.next();
	        if(emp.name.equals("John")){
	            System.out.println(emp.name + "--" + emp.id + "--" + emp.address);
	            it.remove();
	       }
	    }         
	        
	   
		
		
		
	}
}
