package guipackage;

import java.io.File;

/**
 * Фильтр, используемый окном выбора файла.
 * Пропускает только xls файлы.
 */
    class ExcelWorkbookFilter extends javax.swing.filechooser.FileFilter {
        @Override
        public boolean accept(File file) {
            return file.isDirectory() || file.getAbsolutePath().endsWith(".xls");
        }
        @Override
        public String getDescription() {
            return "Книги Excel 2003 (*.xls)";
        }
    } 
