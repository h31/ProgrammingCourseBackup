/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package railway.model;

/**
 *
 * @author RemiX
 */
public class Time {

    private int hours;
    private int minutes;

    public Time(){

    }
    public Time(String time){
        parseToTime(time);
    }
    public int getHours() {
        return hours;
    }

    public void setHours(int hours) {
        this.hours = hours;
    }

    public int getMinutes() {
        return minutes;
    }

    public void setMinutes(int minutes) {
        this.minutes = minutes;
    }

    public void parseToTime(String time) {
        if (time.charAt(0) == '0') {
            hours = Integer.parseInt(time.substring(1, 2));
        } else {
            hours = Integer.parseInt(time.substring(0, 2));
        }
        if (time.charAt(3) == '0') {
            minutes = Integer.parseInt(time.substring(4));
        } else {
            minutes = Integer.parseInt(time.substring(3));
        }
    }
    /*Меньше ли данное время, чем передоваемое в качестве параметра*/

    public boolean isBefore(Time time) {
        if (this.hours >= time.getHours()) {
            if (this.minutes > time.getMinutes()) {
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    }

    public boolean isAfter(Time time) {
        if (this.hours >= time.getHours()) {
            if (this.minutes >= time.getMinutes()) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        if (hours < 10) {
            string.append("0");
        }
        string.append(hours+":");
        if (minutes < 10) {
            string.append("0");
        }
        string.append(minutes);
        return string.toString();
    }
}
