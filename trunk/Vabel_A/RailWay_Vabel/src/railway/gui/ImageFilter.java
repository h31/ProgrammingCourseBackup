/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package railway.gui;

import java.io.File;
import javax.swing.filechooser.FileFilter;

/**
 *
 * @author RemiX
 */
public class ImageFilter extends FileFilter{

    @Override
    public boolean accept(File f) {
        if (f.isDirectory()) {
        return true;
    }

    String extension = getExtension(f);
    if (extension != null) {
        if (
            extension.equals("tif") ||
            extension.equals("gif") ||
            extension.equals("jpeg") ||
            extension.equals("jpg") ||
            extension.equals("png")) {
                return true;
        } else {
            return false;
        }
    }

    return false;
    }

        public String getExtension(File f) {
        String ext = null;
        String s = f.getName();
        int i = s.lastIndexOf('.');

        if (i > 0 &&  i < s.length() - 1) {
            ext = s.substring(i+1).toLowerCase();
        }
        return ext;
    }
    @Override
    public String getDescription() {
        return "Image Format(tif,gif,jpeg,jpg,png)";
    }

}
