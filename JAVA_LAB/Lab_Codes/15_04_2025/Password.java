import java.util.*;

class InvalidPasswordException extends Exception
{
	InvalidPasswordException()
	{
		super();
	}
}

class Password
{
	void password_check(String p)throws InvalidPasswordException
	{
		if(p.length()<8 || !p.matches(".*[\\d].*") || !p.matches(".*[!@#$%^&*].*") || !p.matches(".*[A-Z].*") || !p.matches(".*[a-z].*"))
			throw new InvalidPasswordException();
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter password: ");
		String password = sc.next();
		p1 obj = new p1();
		try
		{
			obj.password_check(password);
			System.out.println("Passoword Accepted!");
		}
		catch (InvalidPasswordException e)
		{
			System.out.println("Invalid Password handled");
		}
		System.out.println("Normal flow of program");
	}
}
