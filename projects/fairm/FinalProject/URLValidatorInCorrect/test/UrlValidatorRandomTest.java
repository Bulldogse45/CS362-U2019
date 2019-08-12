import junit.framework.TestCase;
import java.util.Random;

public class UrlValidatorRandomTest extends TestCase {

   // @org.junit.Test
    private final boolean printStatus = false; //use the framework in github
    private final boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

    private static final int TESTS = 1000;

    public UrlValidatorRandomTest(String testName) {
        super(testName);
    }

    //Selecting the right partition
    public static String selectPart(Random random, String[] array) {
        int n = random.nextInt(array.length);
        return array[n];
    }

    public void testValid() {

        System.out.println("Testing random..."); //test the possible url strings below

        String[] goodScheme = new String [] {"http://", "https://"};
        String[] badScheme = new String [] {"ttp:/", "psps//", "firewall", "256.256.256.256"};
        String[] goodAuthorities = new String [] {"www.twitter", "twitter", "google"};
        String[] badAuthorities = new String [] {"obso.lo", "badauth.it", "co.com.il"};
        String[] goodDomains = new String [] {".com", ".co.uk", ".us", ".gov"};
        String[] badDomains = new String [] {".soap", ".empathy", ".pbsom"};
        String[] goodPaths = new String [] {"/test", "/test/", "", "/test/file"};
        String[] badPaths = new String [] {"", "?", "3981///"};

        int seed = 8;
        Random random = new Random(seed);
        for (int i = 0; i < TESTS; i++) { //valid and invalid false positives and false negatives

            UrlValidator urlVal = new UrlValidator();

            String goodURL = selectPart(random, goodScheme) + selectPart(random, goodAuthorities) + selectPart(random, goodDomains) + selectPart(random, goodPaths);
            String badURL = selectPart(random, badScheme) + selectPart(random, badAuthorities) + selectPart(random, badDomains) + selectPart(random, badPaths);

            if (urlVal.isValid(goodURL)) {
                    System.out.println("This is a valid URL: " + goodURL + " "); //Good URL test case
            } else {
                    System.out.println("Error: This should be an invalid URL : " + goodURL + " ");
            }

            if (!urlVal.isValid(badURL)) {
                System.out.println(("This is an invalid URL: " + badURL + " ")); //Bad URL test case
            } else {
                System.out.println("Error: This should be a valid URL: " + goodURL + "");
            }

        }
    }

}