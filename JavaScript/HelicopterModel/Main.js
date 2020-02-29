

function Main() {
  
    var scene = new THREE.Scene();
    var camera = new THREE.PerspectiveCamera(
             45, // kąt patrzenia kamery (FOV - field of view)
             window.innerWidth / window.innerHeight, // proporcje widoku
             0.1, // min renderowana odległość
             15000 // max renderowana odległość
);

    var renderer = new THREE.WebGLRenderer();
    renderer.setClearColor(0x000000);
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.getElementById("content").appendChild(renderer.domElement);
    camera.position.x = 0;
    camera.position.y = 400;
    camera.position.z = 1005;
    
    startScreen = new StartScreen();
    document.body.appendChild(startScreen.getScreen());
    menuButton = new MenuButton();
    console.log(menuButton.getButton())
    slidery = new Slider();
  

    document.body.appendChild(slidery.getGaz());
    document.body.appendChild(slidery.getSkret());
    document.body.appendChild(slidery.getWys());
   // document.body.appendChild(menuButton.getButton()[0]);
   // document.body.appendChild(menuButton.getButton()[1]);
   // document.body.appendChild(menuButton.getButton()[2]);
    document.getElementById("startowy").appendChild(menuButton.getButton()[0]);
    document.getElementById("startowy").appendChild(menuButton.getButton()[1]);
    document.getElementById("startowy").appendChild(menuButton.getButton()[2]);
    var hel, hel1;
    
    var wybor_helikoptra = menuButton.Wybor();
    
    var sky_box = new SkyBox();
    scene.add(sky_box.getSky());

    var build = new Buildings();
    var skala = "100,100,100";
    build.loadModel(skala);
    scene.add(build.getBuild());
    //console.log(build.getBuild());
    var kontr_kam
    var spr_wyb = setInterval(function () {
        if (menuButton.Wybor() == 1) {

            hel = new Helicopter();
            scene.add(hel.getContainer());
            camera.lookAt(hel.getContainer().position);
            clearInterval(spr_wyb);
        }
        else if (menuButton.Wybor() == 2) {
            hel1 = new Helikopter2();
            hel1.loadModel1();
            scene.add(hel1.ladujGo());
            camera.lookAt(hel1.ladujGo().position);
            console.log("DRUGI HELIKOPTR");
            clearInterval(spr_wyb);
            var kameryy = new MenuScreen();
            document.body.appendChild(kameryy.getMenuScreen())
           // window.addEventListener('click', function () {
             //   kameryy.getMenuScreen().style.display = 'inline-block';
            //})
            window.addEventListener("click", ShowCam);
            kontr_kam = new KontrolerKamery(camera, hel1.ladujGo());
        }
    }, 100);

    

    //  var dal = new THREE.Vector3(0, 500, -2000);
    var canv = new KokpitScreen();
    


    function animateScene() {
       // console.log(slidery.getValGaz())
    //   camera.lookAt(dal)
        //   camera.position.z = parseInt(document.getElementById('cam').value)
        // camera.position.y = parseInt(document.getElementById('cam').value)
        //camera.position.x = '-' + parseInt(document.getElementById('cam').value)
        //  sphere.rotation.y -= 0.006;
        requestAnimationFrame(animateScene);
        renderer.render(scene, camera);
        //    
       
        
        if (hel != null) {
            hel.update();
        }

        if (hel1 != null) {
            if (hel1.Wirniki() != null && hel1 != undefined) {
                // console.log("jest")
     //           console.log(hel1)
                hel1.updateWir();
                hel1.ladujGo().translateZ(-slidery.getValGaz() / 10);
                hel1.ladujGo().translateY(slidery.getValWys() / 10);
                hel1.ladujGo().rotation.y += slidery.getValSkret() / 10000;


                kontr_kam.update()



            }
        }
    }
    animateScene();




    window.addEventListener("keydown", function () {
        console.log(event.which);
        if (event.which == 37) {
            var v = (0.2 * 2 * Math.PI) / 360;
            direction_temp2 = true;

            var x = camera.position.x;
            var y = camera.position.y;
            var z = camera.position.z;

            camera.position.x = x * Math.cos(v) - z * Math.sin(v)*10;
            camera.position.z = z * Math.cos(v) + x * Math.sin(v)*10;

            camera.lookAt(scene.position);
        }
        if (event.which == 39) {
            var v = (0.2 * 2 * Math.PI) / 360;
            direction_temp2 = true;

            var x = camera.position.x;
            var y = camera.position.y;
            var z = camera.position.z;

            camera.position.x = x * Math.cos(v) + z * Math.sin(v)*10;
            camera.position.z = z * Math.cos(v) - x * Math.sin(v)*10;

            camera.lookAt(scene.position);
        }
        if (event.which == 40) { //dół
            var v = (0.2 * 2 * Math.PI) / 360;
            direction_temp2 = true;

            var x = camera.position.x;
            var y = camera.position.y;
            var z = camera.position.z;

            camera.position.x = x * Math.cos(v) + y * Math.sin(v) * 10;
       //     camera.position.z = z * Math.cos(v) + y * Math.sin(v) * 10;
            camera.position.y = y * Math.cos(v) - x * Math.sin(v) * 10;
            camera.lookAt(scene.position);
        }
        if (event.which == 38) { //góra
            var v = (0.2 * 2 * Math.PI) / 360;
            direction_temp2 = true;

            var x = camera.position.x;
            var y = camera.position.y;
            var z = camera.position.z;

            camera.position.x = x * Math.cos(v) - y * Math.sin(v) * 10;
       //     camera.position.z = z * Math.cos(v) - y * Math.sin(v) * 10;
            camera.position.y = y * Math.cos(v) + x * Math.sin(v) * 10;
            camera.lookAt(scene.position);
        }

    })

    
 
}
function ShowCam() {
    document.getElementById("kamery").style.display = 'inline-block';
    window.removeEventListener('click', ShowCam);
}