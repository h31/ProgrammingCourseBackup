/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package minesweeper;

/**
 *
 * @author RemiX
 */
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import java.util.Random;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Board extends JPanel {

    private final int NUM_IMAGES = 13;
    private final int CELL_SIZE = 15;

    private final int COVER_FOR_CELL = 10;
    private final int MARK_FOR_CELL = 10;
    private final int EMPTY_CELL = 0;
    private final int MINE_CELL = 9;
    private final int COVERED_MINE_CELL = MINE_CELL + COVER_FOR_CELL;
    private final int MARKED_MINE_CELL = COVERED_MINE_CELL + MARK_FOR_CELL;

    private final int DRAW_MINE = 9;
    private final int DRAW_COVER = 10;
    private final int DRAW_MARK = 11;
    private final int DRAW_WRONG_MARK = 12;

    private int[] field;
    private boolean inGame;
    private int mines_left;
    private Image[] img;
    private int mines = 40;
    private int rows = 16;
    private int cols = 16;
    private int all_cells;
    private JLabel statusbar;
    private JLabel timerbar;
    private int currentTime=0;
    private Timer timer;
    private boolean isFirstClick=false;
    private Mines frame;

    public Board(JLabel statusbar,JLabel timerbar,Mines frame) {
        this.frame = frame;
        this.statusbar = statusbar;
        this.timerbar = timerbar;
        img = new Image[NUM_IMAGES];

        for (int i = 0; i < NUM_IMAGES; i++) {
            img[i] =(new ImageIcon(this.getClass().getResource((i) + ".png"))).getImage();
        }

        setDoubleBuffered(true);

        addMouseListener(new MinesAdapter());
        initTimer();
        newGame();
    }


    public void newGame() {

        Random random;
        int current_col;

        int i = 0;
        int position = 0;
        int cell = 0;

        random = new Random();
        inGame = true;
        mines_left = mines;

        all_cells = rows * cols;
        field = new int[all_cells];

        for (i = 0; i < all_cells; i++)
            field[i] = COVER_FOR_CELL;

        statusbar.setText(Integer.toString(mines_left));
        isFirstClick=true;
        currentTime=0;
        timerbar.setText(String.valueOf(currentTime));
        timer.stop();

        i = 0;
        while (i < mines) {

            position = (int) (all_cells * random.nextDouble());

            if ((position < all_cells) &&
                (field[position] != COVERED_MINE_CELL)) {


                current_col = position % cols;
                field[position] = COVERED_MINE_CELL;
                i++;

                if (current_col > 0) {
                    cell = position - 1 - cols;
                    if (cell >= 0)
                        if (field[cell] != COVERED_MINE_CELL)
                            field[cell] += 1;
                    cell = position - 1;
                    if (cell >= 0)
                        if (field[cell] != COVERED_MINE_CELL)
                            field[cell] += 1;

                    cell = position + cols - 1;
                    if (cell < all_cells)
                        if (field[cell] != COVERED_MINE_CELL)
                            field[cell] += 1;
                }

                cell = position - cols;
                if (cell >= 0)
                    if (field[cell] != COVERED_MINE_CELL)
                        field[cell] += 1;
                cell = position + cols;
                if (cell < all_cells)
                    if (field[cell] != COVERED_MINE_CELL)
                        field[cell] += 1;

                if (current_col < (cols - 1)) {
                    cell = position - cols + 1;
                    if (cell >= 0)
                        if (field[cell] != COVERED_MINE_CELL)
                            field[cell] += 1;
                    cell = position + cols + 1;
                    if (cell < all_cells)
                        if (field[cell] != COVERED_MINE_CELL)
                            field[cell] += 1;
                    cell = position + 1;
                    if (cell < all_cells)
                        if (field[cell] != COVERED_MINE_CELL)
                            field[cell] += 1;
                }
            }
        }
    }


    public void find_empty_cells(int j) {

        int current_col = j % cols;
        int cell;

        if (current_col > 0) {
            cell = j - cols - 1;
            if (cell >= 0)
                if (field[cell] > MINE_CELL) {
                    field[cell] -= COVER_FOR_CELL;
                    if (field[cell] == EMPTY_CELL)
                        find_empty_cells(cell);
                }

            cell = j - 1;
            if (cell >= 0)
                if (field[cell] > MINE_CELL) {
                    field[cell] -= COVER_FOR_CELL;
                    if (field[cell] == EMPTY_CELL)
                        find_empty_cells(cell);
                }

            cell = j + cols - 1;
            if (cell < all_cells)
                if (field[cell] > MINE_CELL) {
                    field[cell] -= COVER_FOR_CELL;
                    if (field[cell] == EMPTY_CELL)
                        find_empty_cells(cell);
                }
        }

        cell = j - cols;
        if (cell >= 0)
            if (field[cell] > MINE_CELL) {
                field[cell] -= COVER_FOR_CELL;
                if (field[cell] == EMPTY_CELL)
                    find_empty_cells(cell);
            }

        cell = j + cols;
        if (cell < all_cells)
            if (field[cell] > MINE_CELL) {
                field[cell] -= COVER_FOR_CELL;
                if (field[cell] == EMPTY_CELL)
                    find_empty_cells(cell);
            }

        if (current_col < (cols - 1)) {
            cell = j - cols + 1;
            if (cell >= 0)
                if (field[cell] > MINE_CELL) {
                    field[cell] -= COVER_FOR_CELL;
                    if (field[cell] == EMPTY_CELL)
                        find_empty_cells(cell);
                }

            cell = j + cols + 1;
            if (cell < all_cells)
                if (field[cell] > MINE_CELL) {
                    field[cell] -= COVER_FOR_CELL;
                    if (field[cell] == EMPTY_CELL)
                        find_empty_cells(cell);
                }

            cell = j + 1;
            if (cell < all_cells)
                if (field[cell] > MINE_CELL) {
                    field[cell] -= COVER_FOR_CELL;
                    if (field[cell] == EMPTY_CELL)
                        find_empty_cells(cell);
                }
        }

    }

    public void paint(Graphics g) {

        int cell = 0;
        int uncover = 0;


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                cell = field[(i * cols) + j];

                if (inGame && cell == MINE_CELL)
                    inGame = false;

                if (!inGame) {
                    if (cell == COVERED_MINE_CELL) {
                        cell = DRAW_MINE;
                    } else if (cell == MARKED_MINE_CELL) {
                        cell = DRAW_MARK;
                    } else if (cell > COVERED_MINE_CELL) {
                        cell = DRAW_WRONG_MARK;
                    } else if (cell > MINE_CELL) {
                        cell = DRAW_COVER;
                    }


                } else {
                    if (cell > COVERED_MINE_CELL)
                        cell = DRAW_MARK;
                    else if (cell > MINE_CELL) {
                        cell = DRAW_COVER;
                        uncover++;
                    }
                }

                g.drawImage(img[cell], (j * CELL_SIZE),
                    (i * CELL_SIZE), this);
            }
        }


        if (uncover == 0 && inGame) {
            inGame = false;
            statusbar.setText("Победа!");
            timer.stop();
            frame.reqistration(currentTime);
        } else if (!inGame){
            statusbar.setText("Конец игры");
            timer.stop();
        }
    }


    class MinesAdapter extends MouseAdapter {
        public void mousePressed(MouseEvent e) {
            if(isFirstClick){
                timer.start();
                isFirstClick=false;
            }
            int x = e.getX();
            int y = e.getY();

            int cCol = x / CELL_SIZE;
            int cRow = y / CELL_SIZE;

            boolean rep = false;


            if (!inGame) {
                newGame();
                repaint();
            }


            if ((x < cols * CELL_SIZE) && (y < rows * CELL_SIZE)) {

                if (e.getButton() == MouseEvent.BUTTON3) {

                    if (field[(cRow * cols) + cCol] > MINE_CELL) {
                        rep = true;

                        if (field[(cRow * cols) + cCol] <= COVERED_MINE_CELL) {
                            if (mines_left > 0) {
                                field[(cRow * cols) + cCol] += MARK_FOR_CELL;
                                mines_left--;
                                statusbar.setText(Integer.toString(mines_left));
                            } else
                                statusbar.setText("No marks left");
                        } else {

                            field[(cRow * cols) + cCol] -= MARK_FOR_CELL;
                            mines_left++;
                            statusbar.setText(Integer.toString(mines_left));
                        }
                    }

                } else {

                    if (field[(cRow * cols) + cCol] > COVERED_MINE_CELL) {
                        return;
                    }

                    if ((field[(cRow * cols) + cCol] > MINE_CELL) &&
                        (field[(cRow * cols) + cCol] < MARKED_MINE_CELL)) {

                        field[(cRow * cols) + cCol] -= COVER_FOR_CELL;
                        rep = true;

                        if (field[(cRow * cols) + cCol] == MINE_CELL)
                            inGame = false;
                        if (field[(cRow * cols) + cCol] == EMPTY_CELL)
                            find_empty_cells((cRow * cols) + cCol);
                    }
                }

                if (rep)
                    setBounds(0, 0, cols*CELL_SIZE, rows*CELL_SIZE);
                    repaint();

            }
        }
    }

    public void initTimer(){
        timer = new Timer(1000, new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                currentTime++;
                timerbar.setText(String.valueOf(currentTime));
                repaint();
            }
        });
    }

    public int getMines(){
        return this.mines;
    }
    public void setMines(int mines){
        this.mines = mines;
    }

    public int getCols() {
        return cols;
    }

    public void setCols(int cols) {
        this.cols = cols;
    }

    public int getRows() {
        return rows;
    }

    public void setRows(int rows) {
        this.rows = rows;
    }

    public int getCELL_SIZE() {
        return CELL_SIZE;
    }
    

}
