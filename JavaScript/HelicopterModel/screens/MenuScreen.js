function MenuScreen() {

    var container = document.createElement("div");
    //potem style, wielkość, tło etc
    container.style.width = 80 + 'vw';
    container.style.height = 20 + "vh";
    
    container.style.position = "absolute";
    container.style.top = 0;
    container.id = "kamery";

    //   dodaj funkcję zwracającą screen:

    for (var i = 0; i < TrybyKamery.TRYBY.length; i++) {
        var bt = document.createElement("div");
        bt.style.width = 10 + 'vw';
        bt.style.height = 10 + 'vw';
     
        bt.style.position = "absolute";
        bt.style.top =0;
        bt.style.left = i*15+'vw';
 
          bt.setAttribute('name', TrybyKamery.TRYBY[i]);
            bt.style.backgroundImage = "url('" + Materials.HELIKOPTER1_ICONS[i]+"')";
            bt.style.backgroundSize = 'contain';
            bt.style.backgroundRepeat = 'no-repeat';
            bt.addEventListener('click', function () {
                document.getElementById("kamery").style.display = 'none';
                window.addEventListener('mousedown', ShowCam)
                TrybyKamery.WYBRANY_TRYB = this.getAttribute('name');
                console.log(this.getAttribute('name'))
               // console.log("KLIK")
            });
          //  bt.addEventListener('click', HideCam);
            container.appendChild(bt);
        
    }
    container.style.display = 'none';

    this.getMenuScreen = function () {
        return container;
    };
};
function HideCam() {
    document.getElementById("kamery").style.display = 'none';
    window.addEventListener('click',ShowCam)
}