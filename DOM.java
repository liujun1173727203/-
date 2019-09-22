package bean;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;

/**
 * Created by 小二 on 2019/9/22.
 */
public class DOM {
    public static void main(String[] args) {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder =null;
        try{
            builder =factory.newDocumentBuilder();
        }catch (ParserConfigurationException e){
            e.printStackTrace();
        }
        Document doc = null;
        doc = builder.newDocument();
        Element configuration1 =doc.createElement("configuration1");
        Element linkman =doc.createElement("linkman");
        Element name =doc.createElement("name");
        Element email =doc.createElement("email");
        name.appendChild(doc.createTextNode("aaa"));
        email.appendChild(doc.createTextNode("bbb"));
        linkman.appendChild(name);
        linkman.appendChild(email);
        configuration1.appendChild(linkman);
        doc.appendChild(configuration1);
        TransformerFactory tf = TransformerFactory.newInstance();
        Transformer t =null;
        try{
            t = tf.newTransformer();
        }catch (TransformerConfigurationException e1){
            e1.printStackTrace();
        }
        t.setOutputProperty(OutputKeys.ENCODING,"GBK");
        DOMSource source =  new DOMSource(doc);
        StreamResult result =new StreamResult(new File("d:"+File.separator+"output.xml"));
        try{
            t.transform(source,result);
        }catch (TransformerException e){
            e.printStackTrace();
        }
    }
}
