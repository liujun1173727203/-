package bean;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
/**
 * Created by 小二 on 2019/9/22.
 */
public class mysax extends DefaultHandler{
    @Override
    public void startDocument() throws SAXException {
        System.out.println("<?xml version=\"1.0\" encoding=\"GBK\"?>");
    }

    @Override
    public void endDocument() throws SAXException {
    System.out.println("\n 文档读取结束");
    }

    @Override
    public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
        System.out.print("<");
        System.out.print(qName);
        if (attributes!=null){
            for (int x = 0;x<attributes.getLength();x++){
                System.out.print(""+attributes.getQName(x)+"=\""+attributes.getValue(x)+"\"");
            }
        }
        System.out.print(">");
    }

    @Override
    public void characters(char[] ch, int start, int length) throws SAXException {
        System.out.print(new String(ch,start,length));
    }

    @Override
    public void endElement(String uri, String localName, String qName) throws SAXException {
        System.out.print("</");
        System.out.print(qName);
        System.out.print(">");
    }
}
