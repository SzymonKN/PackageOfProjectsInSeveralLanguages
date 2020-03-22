public enum Direction{
	LEFT(0,-1),
	RIGHT(0,1),
	UP(-1,0),
	DOWN(1,0);

	int x,y;

	Direction(int xx,int yy){
		x=xx;
		y=yy;

	}
	public String toString(){
		return "[ "+x + " , " + y + " ]";
	}
	public int getX(){
		return this.x;
	}
	public int getY(){
		return this.y;
	}
}