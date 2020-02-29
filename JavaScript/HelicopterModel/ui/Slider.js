var interwal;
function Slider() {
    var div_gaz = document.createElement("div");
    div_gaz.style.position = 'absolute';
    div_gaz.style.height = 90 + "vh";
    div_gaz.style.width = 6 + "vw";
    div_gaz.style.left = 10 + 'px';
    div_gaz.style.top = 5 + 'vh';
    div_gaz.style.backgroundColor = 'rgba(111, 111, 111, 0.4)';


    var wsk_gaz = document.createElement("div");
    wsk_gaz.id="wsk_gaz"
    wsk_gaz.style.position = "absolute";
    wsk_gaz.style.height = 6 + 'vw';
    wsk_gaz.style.width = 6 + 'vw';
    wsk_gaz.style.left = 0;
    wsk_gaz.style.top = 40+'vh';
    wsk_gaz.innerHTML = 'THROTTLE';
    wsk_gaz.style.fontSize = '14px';
    wsk_gaz.style.textAlign = 'center';
    wsk_gaz.style.backgroundColor = 'rgba(102, 153, 255,0.9)'
    wsk_gaz.setAttribute('value', '0');
    wsk_gaz.addEventListener('mousedown', function(){
        window.addEventListener('mousemove',SterGora);
    })

   wsk_gaz.addEventListener('mouseup', function () {
         window.removeEventListener('mousemove',SterGora)
       //  window.removeEventListener('mousemove', SterWys)
      //   window.removeEventListener('mousemove', SterObr)
    })
    div_gaz.appendChild(wsk_gaz);

    this.getGaz = function () {
        return div_gaz;
    }






    var div_skret = document.createElement("div");
    div_skret.style.position = 'absolute';
    div_skret.style.height = 8 + 'vh';
    div_skret.style.width = 80 + 'vw';
    div_skret.style.left = 10 + 'vw';
    div_skret.style.bottom = 10 + 'px';
    div_skret.style.backgroundColor = 'rgba(111, 111, 111, 0.4)';

    var wsk_skret = document.createElement("div");
    wsk_skret.id="wsk_skret"
    wsk_skret.style.position = "absolute";
    wsk_skret.style.height = 8 + 'vh';
    wsk_skret.style.width = 8 + 'vh';
    wsk_skret.style.left = 38+'vw';
    wsk_skret.style.top = 0 ;
    wsk_skret.innerHTML = 'RUDDER';
    wsk_skret.style.fontSize = '14px';
    wsk_skret.style.textAlign = 'center';
    wsk_skret.setAttribute('value', '0');
    wsk_skret.style.backgroundColor = 'rgba(102, 153, 255,0.9)'
    wsk_skret.addEventListener('mousedown', function () {
        window.addEventListener('mousemove', SterObr);
    })
    wsk_skret.addEventListener('mouseup', function () {
        //  window.removeEventListener('mousemove',SterGora)
        //window.removeEventListener('mousemove', SterWys)
           window.removeEventListener('mousemove', SterObr)
    })
    div_skret.appendChild(wsk_skret);

    this.getSkret = function () {
        return div_skret;
    }






    var div_wys = document.createElement("div");
    div_wys.style.position = 'absolute';
    div_wys.style.height = 90 + "vh";
    div_wys.style.width = 6+ "vw";
    div_wys.style.right = 10 + 'px';
    div_wys.style.top = 5 + 'vh';
    div_wys.style.backgroundColor = 'rgba(111, 111, 111, 0.4)';

    var wsk_wys = document.createElement("div");
    wsk_wys.id="wsk_wys"
    wsk_wys.style.position = "absolute";
    wsk_wys.style.height = 6 + 'vw';
    wsk_wys.style.width = 6 + 'vw';
    wsk_wys.style.left = 0;
    wsk_wys.style.top = 40 + 'vh';
    wsk_wys.innerHTML = 'ELEVATION';
    wsk_wys.style.fontSize = '14px';
    wsk_wys.style.textAlign = 'center';
    wsk_wys.style.backgroundColor = 'rgba(102, 153, 255,0.9)';
    wsk_wys.setAttribute('value', '0');
    wsk_wys.addEventListener('mousedown', function () {
        window.addEventListener('mousemove', SterWys);
    })
    wsk_wys.addEventListener('mouseup', function () {
        //  window.removeEventListener('mousemove',SterGora)
        window.removeEventListener('mousemove', SterWys)
        //   window.removeEventListener('mousemove', SterObr)
    })

    div_wys.appendChild(wsk_wys);


    this.getWys = function () {
        return div_wys;
    }

    function SterGora() {
        var rect = div_gaz.getBoundingClientRect();
        //    //   document.getElementById("thumb_x").style.left = parseInt(event.clientX - rect.left-10) + 'px';
        wsk_gaz.style.top = parseInt(event.clientY - rect.top - parseInt(wsk_gaz.style.height)/100*window.innerHeight) + "px";
     //   console.log(parseInt(wsk_gaz.style.height)/100*window.innerHeight)
        wsk_gaz.value = parseInt(event.clientY - rect.top);
        wsk_gaz.setAttribute('value',parseInt(wsk_gaz.style.top) * (-1) + parseInt(div_gaz.style.height) / 100 * window.innerHeight/2 - parseInt(wsk_gaz.style.height) / 100 * window.innerHeight)
      //  console.log(parseInt(wsk_gaz.style.top) * (-1) + parseInt(div_gaz.style.height) / 100 * window.innerHeight/2 - parseInt(wsk_gaz.style.height) / 100 * window.innerHeight)
        //  console.log("muuuuuf");



    }
    function SterWys() {
        var rect = div_wys.getBoundingClientRect();
        //    //   document.getElementById("thumb_x").style.left = parseInt(event.clientX - rect.left-10) + 'px';
        wsk_wys.style.top = parseInt(event.clientY - rect.top - parseInt(wsk_wys.style.height) / 100 * window.innerHeight) + "px";
        wsk_wys.setAttribute('value', parseInt(wsk_wys.style.top) * (-1) + parseInt(div_wys.style.height) / 100 * window.innerHeight / 2 - parseInt(wsk_wys.style.height) / 100 * window.innerHeight)
    }
    function SterObr() {
        var rect = div_skret.getBoundingClientRect();
        //    //   document.getElementById("thumb_x").style.left = parseInt(event.clientX - rect.left-10) + 'px';
        wsk_skret.style.left = parseInt(event.clientX - rect.left - parseInt(wsk_skret.style.width) / 100 * window.innerHeight/2) + "px";
        //    console.log(parseInt(wsk_skret.style.width) / 100 * window.innerWidth)
        wsk_skret.setAttribute('value', parseInt(wsk_skret.style.left) * (-1) + parseInt(div_skret.style.width) / 100 * window.innerWidth / 2 - parseInt(wsk_skret.style.width) / 100 * window.innerHeight)
    }



    this.getValGaz = function () {
        return wsk_gaz.getAttribute('value');
    }
    this.getValWys = function () {
        return wsk_wys.getAttribute('value');
    }
    this.getValSkret = function () {
        return wsk_skret.getAttribute('value');
    }
}
