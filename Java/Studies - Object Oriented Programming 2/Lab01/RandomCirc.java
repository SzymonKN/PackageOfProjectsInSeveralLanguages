import java.util.Random;

public class RandomCirc {
    public static void main(String[] args) {
        if(args.length != 0){
        int n = Integer.parseInt(args[0]);
        int r_max = Integer.parseInt(args[1]);
        double alfa = 2*Math.PI;

        Random rand = new Random();
        for(int i=0;i<n;i++){
                double r = r_max * rand.nextDouble();
                double a = alfa * rand.nextDouble();
                double x = Math.cos(a) * r;
                double y = Math.sin(a) * r;
                System.out.println("" + x + " " + y);
        }
    }
}
}

