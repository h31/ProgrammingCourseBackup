/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package minesweeper.datahandle;

/**
 *
 * @author RemiX
 */
public class User implements Comparable<User> {
    private String name;
    private String level;
    private int time;

    public String getLevel() {
        return level;
    }

    public void setLevel(String level) {
        this.level = level;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getTime() {
        return time;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public User(String name, String level, int time) {
        this.name = name;
        this.level = level;
        this.time = time;
    }

    public User() {
    }

    public int compareTo(User o) {
        return this.time - o.getTime();
    }
    

}
