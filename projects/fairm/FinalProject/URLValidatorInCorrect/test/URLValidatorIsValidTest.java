
import static org.junit.Assert.*;
//https://stackoverflow.com/questions/9259411/what-is-the-best-way-to-iterate-over-the-lines-of-a-java-string
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class URLValidatorIsValidTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testIsValid() throws IOException {
		UrlValidator uvi=new UrlValidator();
		// https://www.randomlists.com/urls for urls
		
		BufferedReader invalidUrlList = new BufferedReader(new FileReader("test\\test_invalid_urls.txt"));
		String nonUrl=null;
		while( (nonUrl=invalidUrlList.readLine()) != null )
		{
			if(uvi.isValid(nonUrl))
				System.out.print("This  should not be valid: " + nonUrl); 
			assertFalse(uvi.isValid(nonUrl));
		}
		invalidUrlList.close();
		
		BufferedReader urlList = new BufferedReader(new FileReader("test\\test_valid_urls.txt"));
		String url=null;
		while( (url=urlList.readLine()) != null )
		{
			if(!uvi.isValid(url))
				System.out.print("This should be valid: " + url); 
			assertTrue(uvi.isValid(url));
		}
		urlList.close();

	}

}
