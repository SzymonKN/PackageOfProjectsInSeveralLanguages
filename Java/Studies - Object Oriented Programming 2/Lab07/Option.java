public enum Option{
	RESET('0',"opcja RESET, opis: Reset planszy",null),
	LEFT('l' ," opcja LEFT, opis: Przesun w lewo, wektor przesuniecia:",Direction.LEFT),
	RIGHT('r' ," opcja RIGHT, opis: Przesun w prawo, wektor przesuniecia:",Direction.RIGHT),
	UP('u' ," opcja UP, opis: Przesun w gore, wektor przesuniecia:",Direction.UP),
	DOWN('d' ,"opcja DOWN, opis: Przesun w dol, wektor przesuniecia:",Direction.DOWN),
	EXIT('q' ," opcja EXIT, opis: Zakonczenie gry",null);
	String opis;
	char znak;
	Direction kierunek;
	Option(char z,String text,Direction d){
		opis=text;
		znak=z;
		kierunek=d;
	}
	public String toString(){
		return "'"+znak+"'" +" ==> " +opis +" "+ kierunek+"\n";
	}
	public char getZnak(){
		return this.znak;
	}
	public String getOpis(){
		return this.opis;
	}
	public Direction getKierunek(){
		return this.kierunek;
	}
}