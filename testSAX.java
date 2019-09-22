package bean;

import org.xml.sax.SAXException;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;

/**
 * Created by 小二 on 2019/9/22.
 */
public class testSAX {
    public static void main(String[] arg) throws Exception {
        SAXParserFactory factory =SAXParserFactory.newInstance();
        SAXParser parser =factory.newSAXParser();
        parser.parse("d:"+ File.separator+"output.xml",new mysax());
    }
}
