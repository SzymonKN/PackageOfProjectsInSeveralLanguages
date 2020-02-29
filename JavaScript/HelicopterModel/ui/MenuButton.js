function MenuButton() {
    var obiekt1 = {};
    var obiekt2 = {};
    obiekt1.buttony = [];
    var wybor_helikoptera;
    for (var i = 1; i <= Materials.Helikoptry.length; i++) {
       var bt = document.createElement("div");
        bt.style.width = 10 + 'vw';
        bt.style.height = 10 + 'vw';
        bt.style.backgroundColor = "brown";
        bt.style.position = "absolute";
        bt.style.top = 20+"vh";
        bt.style.left = i * 30 + "vw";
        if (i == 1) {
            bt.innerHTML = "1";
        }
        else bt.innerHTML = "2";
        bt.style.fontSize = 50 + 'px';
        bt.addEventListener('click', function () {
            this.style.backgroundColor = "silver";
            console.log(this.innerHTML);
            wybor_helikoptera = this.innerHTML;
        })
        obiekt1.buttony.push(bt);
    }
    
    var bt = document.createElement("div");
    bt.style.width = 10 + 'vw';
    bt.style.height = 10 + 'vw';
    bt.style.backgroundColor = "grey";
    bt.style.position = "absolute";
    bt.style.top = 40 + "vh";
    bt.style.left =  40 + "vw";
    bt.innerHTML = "Start";
    bt.style.fontSize = 50 + 'px';
    bt.addEventListener('click', function () {
        if(wybor_helikoptera!=null)
        document.getElementById("startowy").style.display = 'none';
      
    })
    obiekt1.buttony.push(bt);



    this.setPosition = function (params) {
        //tą funkcją ustalisz pozycję buttona      
    }

    this.getButton = function () {
        return obiekt1.buttony;
    }
    this.Wybor = function () {
        return wybor_helikoptera;
    }
};
