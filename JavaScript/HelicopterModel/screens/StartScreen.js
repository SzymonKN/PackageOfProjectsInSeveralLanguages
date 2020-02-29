function StartScreen() {

    var screen = document.createElement("div");
    //potem style, wielkość, tło etc
    screen.style.width = 100+'vw';
    screen.style.height = 100 + "vh";
    screen.style.backgroundColor = "black";
    screen.style.position = "absolute";
    screen.style.top = 0;
    screen.id = "startowy";

//   dodaj funkcję zwracającą screen:

        this.getScreen = function () {
            return screen;
        };
};