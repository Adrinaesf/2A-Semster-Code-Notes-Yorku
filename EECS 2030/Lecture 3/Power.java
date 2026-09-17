public class Power {

	public Power() {
		// TODO Auto-generated constructor stub
	}
	
	public static int power (int base, int n)   // assume n >= 0
	{
	  if(n == 0) /* base case  */
	    return 1;
	  else
	    return base * power (base, n-1);
	}
	
	
	static int power2 (int base, int n)   // assume n >= 0
	{
	  if(n == 0) /* base case  */
	    return 1;
	  else{
	    if (n%2==0) { // n is even
	      int powHalf = power2 (base, n/2);
	      return powHalf * powHalf; }
	    else { // n is odd
	      int powHalf = power2 (base, (n-1)/2);
	      return base * powHalf * powHalf;
	      }
	    }
	  }

	
	


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a = power2 (2, 4);
		System.out.println("A " + a);

	}

}