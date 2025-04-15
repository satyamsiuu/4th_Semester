import java.util.*;

class InsufficientFunds extends RuntimeException
{
	InsufficientFunds(String m)
	{
		super(m);
	}
}

class Bank
{
	String name;
	double balance;

	Bank(String name,double balance)
	{
		this.name = name;
		this.balance = balance;
	}
	
	void deposit(double amt)
	{
		balance+=amt;
	}

	void withdraw(double amt)
	{
		if(amt>balance)
			throw new InsufficientFunds("No funds");
		else 
			balance-=amt;
	}	
}

public class Bank_System
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Name: ");
		String name = sc.nextLine();
		System.out.println("Enter Balance: ");
		double balance = sc.nextDouble();
		System.out.println("Enter Withdrawl amount: ");
		double amt = sc.nextDouble();
		Bank obj = new Bank(name,balance);
		try
		{
			obj.withdraw(amt);
			System.out.println("Withdrawl Successfull!");
		}
		catch(InsufficientFunds e)
		{
			System.out.println("Insufficient Funds Exception handled!");
		}
		System.out.println("Normal Flow");
	}
}
		
		
