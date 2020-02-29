var klocek;

var licznik_kolor = 0;
var licznik_size = 0;
function Main() {
    var camera = new THREE.OrthographicCamera(
        window.innerWidth / -2,
        window.innerWidth / 2,
        window.innerHeight / 2,
        window.innerHeight / -2,
        -5000,
        5000);
    var scene = new THREE.Scene();
    var renderer = new THREE.WebGLRenderer();
    renderer.setClearColor(0xffffff);
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.getElementById("content").appendChild(renderer.domElement);
    camera.position.x = 0;
    camera.position.y = 512;
    camera.position.z = 2048;
    var light1 = new THREE.DirectionalLight(0xffffff, 25);
    light1.position.set(1, 1, 0);
    scene.add(light1);
    var text = new Intro();
    console.log(text.getText())
    scene.add(text.getText());
    camera.lookAt(scene.position);

 
    var tablica_kol = [
new THREE.Color(0xff0000),
new THREE.Color(0x9900ff),
new THREE.Color(0x0000ff),
new THREE.Color(0x00ff00),
    ];
   

  
    




    function animateScene() {
        //   camera.position.z = parseInt(document.getElementById('cam').value)
        // camera.position.y = parseInt(document.getElementById('cam').value)
        //camera.position.x = '-' + parseInt(document.getElementById('cam').value)
        //  sphere.rotation.y -= 0.006;
        requestAnimationFrame(animateScene);
        renderer.render(scene, camera);


       
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

            camera.position.x = x * Math.cos(v) - z * Math.sin(v) * 10;
            camera.position.z = z * Math.cos(v) + x * Math.sin(v) * 10;

            camera.lookAt(scene.position);
        }
        if (event.which == 39) {
            var v = (0.2 * 2 * Math.PI) / 360;
            direction_temp2 = true;

            var x = camera.position.x;
            var y = camera.position.y;
            var z = camera.position.z;

            camera.position.x = x * Math.cos(v) + z * Math.sin(v) * 10;
            camera.position.z = z * Math.cos(v) - x * Math.sin(v) * 10;

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
        if (event.which == 67) { //kolorowanie c
            console.log(klocek.getKlocek().children[0].material.color);
            
            client.emit("kolorowanie", {
                col: licznik_kolor
            })

            if (licznik_kolor == 0) {
                for (var j = 0;j<klocek.getKlocek().children.length;j++)
                 klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
                licznik_kolor++;
            }
            else if (licznik_kolor == 1) {
            //    klocek.getKlocek().children[0].material.color = tablica_kol[licznik_kolor];
              for (var j = 0; j < klocek.getKlocek().children.length; j++)
                    klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
                licznik_kolor++;
            }
            else if (licznik_kolor == 2) {
                for (var j = 0; j < klocek.getKlocek().children.length; j++)
                    klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
                //klocek.getKlocek().children[0].material.color = tablica_kol[licznik_kolor];
                licznik_kolor++;
            }
            else if (licznik_kolor == 3) {
                for (var j = 0; j < klocek.getKlocek().children.length; j++)
                    klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
               // klocek.getKlocek().children[0].material.color = tablica_kol[licznik_kolor];
                licznik_kolor = 0;
            }
           

        }
        if (event.which == 87) { //W
            klocek.getKlocek().position.z -= 25
            client.emit("ruszanie", {
                posX:   klocek.getKlocek().position.x, 
                posZ: klocek.getKlocek().position.z
            })
        }
        if (event.which == 83) { //S
            klocek.getKlocek().position.z += 25
            client.emit("ruszanie", {
                posX: klocek.getKlocek().position.x,
                posZ: klocek.getKlocek().position.z
            })
        }
        if (event.which == 68) { //D
            klocek.getKlocek().position.x += 25
            client.emit("ruszanie", {
                posX: klocek.getKlocek().position.x,
                posZ: klocek.getKlocek().position.z
            })
        }
        if (event.which == 65) { //A
            klocek.getKlocek().position.x -= 25
            client.emit("ruszanie", {
                posX: klocek.getKlocek().position.x,
                posZ: klocek.getKlocek().position.z
            })
        }
        if (event.which == 88) { //X RESIZE
            client.emit("dobudowanie", {
                licz: licznik_size
            })
            if (licznik_size < 3) {
                var dob = new Dobudowanie();
                klocek.getKlocek().add(dob.getDob());
                dob.getDob().position.x += 50 + licznik_size * 25;
                licznik_size++;
            }
            else if (licznik_size >= 3) {
               
                klocek.getKlocek().remove(klocek.getKlocek().children[klocek.getKlocek().children.length-1])
                console.log(licznik_size)
                licznik_size++
                if (licznik_size == 6)
                    licznik_size = 0;
            }
           
        }
        if (event.which == 82) { //R
            klocek.getKlocek().rotateY(Math.PI / 2);
            console.log(klocek.getKlocek().rotation.y)
            client.emit("obracanie", {
                rot:  klocek.getKlocek().rotation.y
            })
        }

    })

    var i, j;
    window.addEventListener("click", onClick, false);
    var raycaster = new THREE.Raycaster(); // obiekt symulujący "rzucanie" promieni
    var mouseVector = new THREE.Vector2()

    function onClick(event) {
        // wektor (x,y) wykorzystany bedzie do określenie pozycji myszy na ekranie
        //pozycja myszy zostaje przeliczona na wartości 0-1, wymagane przez raycaster
        mouseVector.x = (event.clientX / window.innerWidth) * 2 - 1;
        mouseVector.y = -(event.clientY / window.innerHeight) * 2 + 1;
        // console.log(klik)
        // szukamy punktów wspólnych "promienia" i obiektu 3D 
        raycaster.setFromCamera(mouseVector, camera);
        //intersects - tablica obiektów w które "trafia" nasz "promień" wysyłany z kamery
        var intersects = raycaster.intersectObjects(scene.children);
        // console.log(intersects.length)
        //jeśli długość tablicy > 0 oznacza to że "trafilismy" w obiekt 3D czyli "kliknelismy" go
        console.log(intersects.length);
        if (intersects.length > 0) {
            // klik++;
            // zerowy czyli najbliższy kamery jest tek którego potrzebujemy   
           
            console.log(intersects[0].object)
            scene.remove(intersects[0].object)
            var game = new Game();
            game.getPlansza(scene);
            window.removeEventListener("click", onClick, false);
            window.addEventListener("click", onClick2, false);



        }
    }
    function onClick2(event) {
        // wektor (x,y) wykorzystany bedzie do określenie pozycji myszy na ekranie
        //pozycja myszy zostaje przeliczona na wartości 0-1, wymagane przez raycaster
        mouseVector.x = (event.clientX / window.innerWidth) * 2 - 1;
        mouseVector.y = -(event.clientY / window.innerHeight) * 2 + 1;
        // console.log(klik)
        // szukamy punktów wspólnych "promienia" i obiektu 3D 
        raycaster.setFromCamera(mouseVector, camera);
        //intersects - tablica obiektów w które "trafia" nasz "promień" wysyłany z kamery
        var intersects = raycaster.intersectObjects(scene.children,true);
        // console.log(intersects.length)
        //jeśli długość tablicy > 0 oznacza to że "trafilismy" w obiekt 3D czyli "kliknelismy" go
        console.log(intersects.length);
        if (intersects.length > 0) {
            // klik++;
            // zerowy czyli najbliższy kamery jest tek którego potrzebujemy    
            if (intersects[0].object.name == 'siatka') {
                console.log(intersects[0].object);
                klocek = new Klocek();
                klocek.getKlocek().position.x = intersects[0].object.position.x 
                klocek.getKlocek().position.z = intersects[0].object.position.z 
                licznik_kolor = 0;
                scene.add(klocek.getKlocek())

                client.emit("budowanie", {
                    posX: intersects[0].object.position.x,
                    posY: intersects[0].object.position.z,
                    posZ: 0
                })

            }
            else if (intersects[0].object.name == 'klocek') {
                console.log(intersects[0].object);
                klocek = new Klocek();
                klocek.getKlocek().position.x = intersects[0].object.parent.position.x 
                klocek.getKlocek().position.z = intersects[0].object.parent.position.z
                klocek.getKlocek().position.y = intersects[0].object.parent.position.y + 30;
                licznik_kolor = 0;
                licznik_size = 0;
                scene.add(klocek.getKlocek())
                client.emit("budowanie", {
                    posX: intersects[0].object.parent.position.x ,
                    posY: intersects[0].object.parent.position.z,
                    posZ: intersects[0].object.parent.position.y + 30
                })
            }
         
         //   scene.remove(intersects[0].object)
           // var game = new Game();
           // game.getPlansza(scene);
           // window.removeEventListener("click", onClick, false);
           // window.addEventListener("click", onClick2, false);



        }
    }


    var client = io();

    client.on("budowanie", function (data) {

        klocek = new Klocek();
        klocek.getKlocek().position.x = data.posX
        klocek.getKlocek().position.z = data.posY
        klocek.getKlocek().position.y = data.posZ
        console.log(data.posZ)
        licznik_kolor = 0;
        licznik_size = 0;
        scene.add(klocek.getKlocek())
    })

    client.on("kolorowanie", function (data) {
        licznik_kolor=data.col
        if (licznik_kolor == 0) {
            for (var j = 0; j < klocek.getKlocek().children.length; j++)
                klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
            licznik_kolor++;
        }
        else if (licznik_kolor == 1) {
            //    klocek.getKlocek().children[0].material.color = tablica_kol[licznik_kolor];
            for (var j = 0; j < klocek.getKlocek().children.length; j++)
                klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
            licznik_kolor++;
        }
        else if (licznik_kolor == 2) {
            for (var j = 0; j < klocek.getKlocek().children.length; j++)
                klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
            //klocek.getKlocek().children[0].material.color = tablica_kol[licznik_kolor];
            licznik_kolor++;
        }
        else if (licznik_kolor == 3) {
            for (var j = 0; j < klocek.getKlocek().children.length; j++)
                klocek.getKlocek().children[j].material.color = tablica_kol[licznik_kolor];
            // klocek.getKlocek().children[0].material.color = tablica_kol[licznik_kolor];
            licznik_kolor = 0;
        }
       
    })
    client.on("ruszanie", function (data) {
        klocek.getKlocek().position.x = data.posX
        klocek.getKlocek().position.z = data.posZ
    })
    client.on("dobudowanie", function (data) {
        licznik_size = data.licz;
        if (licznik_size < 3) {
            var dob = new Dobudowanie();
            klocek.getKlocek().add(dob.getDob());
            dob.getDob().position.x += 50 + licznik_size * 25;
            licznik_size++;
        }
        else if (licznik_size >= 3) {

            klocek.getKlocek().remove(klocek.getKlocek().children[klocek.getKlocek().children.length - 1])
            console.log(licznik_size)
            licznik_size++
            if (licznik_size == 6)
                licznik_size = 0;
        }
    })
    client.on("obracanie", function (data) {
        klocek.getKlocek().rotateY(Math.PI / 2)
    })
}