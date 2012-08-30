/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package race;

import java.awt.Color;
import java.awt.Graphics;


public class Blockview 
{
    private Block block;
    
    
    
    public Blockview(Block block_)
    {
        this.block=block_;
    }
    
    void paint(Graphics g)
    {
        
        g.setColor(block.get_color());
        g.fillRect(block.get_x(),block.get_y(),block.get_width(),block.get_heigth());
    }
}
