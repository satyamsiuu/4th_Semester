import java.util.*;

class EmployeeDetailsException extends RuntimeException
{
	EmployeeDetailsException(String message)
	{
		super(message);
	}
}

public class Employee
{
	void employee_validator(String name,int id,int dept_Id)
	{
		if(!(name.charAt(0)>='A' && name.charAt(0)<='Z') || !(id>=2001 && id<=5001) || !(dept_Id>=1 && dept_Id<=5))
				throw new EmployeeDetailsException("\n1)Name should start with capital letter\n2)id between 2001 & 5001\n3)dept_ID betweem 1&5");
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Name: ");
		String name = sc.nextLine();
		System.out.print("Enter ID: ");
		int id = sc.nextInt();
		System.out.print("Enter Department ID: ");
		int dept_Id = sc.nextInt();
		Employee obj = new Employee();
		try
		{
			obj.employee_validator(name,id,dept_Id);
			System.out.println("Details Excepted!");
		}
		catch(EmployeeDetailsException e)
		{
			System.out.println("Invaid Details Exception:\n"+e);
		}
		System.out.println("Normal flow");
	}
}
