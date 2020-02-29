function KokpitScreen() {


    function init() {

        canvas = document.createElement("canvas");
        canvas.id = "canvas1";
        canvas.width = 300;
        canvas.height = 300;
        canvas.style.position = "absolute";
        canvas.style.left = "200px";
        canvas.style.top = "100px";
        canvas.style.background = "rgba(0, 0, 0, 0.2)";
        context = canvas.getContext('2d');
        document.getElementById("content").appendChild(canvas);
        //
        canvas2 = document.createElement("canvas");
        canvas2.id = "canvas2";
        canvas2.width = 300;
        canvas2.height = 300;
        canvas2.style.position = "absolute";
        canvas2.style.left = "800px";
        canvas2.style.bottom = "80px";
        canvas2.style.background = "rgba(255,255,255, 0.2)";
        context2 = canvas2.getContext('2d');
        document.getElementById("content").appendChild(canvas2);
        //
        canvas3 = document.createElement("canvas");
        canvas3.id = "canvas3";
        canvas3.width = 300;
        canvas3.height = 300;
        canvas3.style.position = "absolute";
        canvas3.style.right = "200px";
        canvas3.style.top = "100px";
        canvas3.style.background = "rgba(0, 0, 0, 0.2)";
        context3 = canvas3.getContext('2d');
        document.getElementById("content").appendChild(canvas3);

        function obracaj3(angle) {

            context2.clearRect(0, 0, 300, 300);
            context2.save()
            context2.translate(150, 150)
            context2.rotate(angle)
            context2.translate(-150, -150)

            var img = document.getElementById("roza");
            var pat = context2.createPattern(img, "no-repeat");
            //prostokat
            context2.fillStyle = pat;
            context2.fillRect(0, 0, 300, 300);
            context2.restore()


        }

        document.getElementById("wsk_wys")
        .addEventListener("mousemove", function () {
            rysuj(this.getAttribute('value'), 0)
        })
        document.getElementById("wsk_gaz")
            .addEventListener("mousemove", function () {
                rysuj2(this.getAttribute('value'), 0)
            })



        function rysuj(val) {

            // maska - obszar poza nią nie jest rysowany

            context3.rect(100, 0, 100, 3000);
            context3.clip();

            // stale odswiezanie określonego obszaru
            context3.clearRect(0, 0, 300, 300);

            //linie
            context3.beginPath();
            context3.lineWidth = 10;
            context3.strokeStyle = 'rgba(89, 189, 222, 1)';
            context3.moveTo(100, 0);
            context3.lineTo(100, 300);
            context3.moveTo(200, 0);
            context3.lineTo(200, 300);
            context3.stroke();
            context3.closePath()

            if (val >= 0) {
                //  context.fillRect(100, -val, 100, 400);
                for (i = 0; i < 400; i += 10) {
                    context3.moveTo(150, 10 * i - val);
                    context3.lineTo(200, 10 * i - val);

                    context3.stroke();
                    context3.font = "26px arial";
                    context3.fillStyle = "rgba(255, 255, 255, 1)";
                    if (val >= 0) {
                        context3.fillText(i, 120, 10 * i - val);
                    } else {
                        context3.fillText(i, 120, 10 * i - val);
                    }
                }
            } else {
                for (i = 0; i < 400; i += 10) {
                    context3.moveTo(150, 10 * i - val);
                    context3.lineTo(200, 10 * i - val);
                    context3.stroke();
                    context3.font = "26px arial";
                    context3.fillStyle = "rgba(255, 255, 255, 1)";
                    if (val >= 0) {
                        context3.fillText(i, 120, 10 * i - val);
                    } else {
                        context3.fillText(i, 120, 10 * i - val);
                    }
                }
            }


        }
        //start rysuj
        rysuj(0, 0)
        function rysuj2(val) {

            // maska - obszar poza nią nie jest rysowany

            context.rect(100, 0, 100, 3000);
            context.clip();

            // stale odswiezanie określonego obszaru
            context.clearRect(0, 0, 300, 300);

            //linie
            context.beginPath();
            context.lineWidth = 10;
            context.strokeStyle = 'rgba(89, 189, 222, 1)';
            context.moveTo(100, 0);
            context.lineTo(100, 300);
            context.moveTo(200, 0);
            context.lineTo(200, 300);
            context.stroke();
            context.closePath()
            //napis

            //prostokat
            //wypełniony
            context.beginPath();
            //   cotext3.fillStyle = "rgba(255, 255, 0, 1)";
            // context3.lineWidth = 10;
            //var img = document.getElementById("lin");
            //   var pat = context2.createPattern(img, "repeat");
            //prostokat
            //  context.fillStyle = "#ffff00";
            if (val >= 0) {
                //  context.fillRect(100, -val, 100, 400);
                for (i = 0; i < 400; i += 10) {
                    context.moveTo(100, 10 * i - val);
                    context.lineTo(150, 10 * i - val);

                    context.stroke();
                    context.font = "26px arial";
                    context.fillStyle = "rgba(255, 255, 255, 1)";
                    if (val >= 0) {
                        context.fillText(i, 150, 10 * i - val);
                    } else {
                        context.fillText(i, 150, 10 * i - val);
                    }
                }
            } else {
                for (i = 0; i < 400; i += 10) {
                    context.moveTo(100, 10 * i + val);
                    context.lineTo(150, 10 * i + val);
                    context.stroke();
                    context.font = "26px arial";
                    context.fillStyle = "rgba(255, 255, 255, 1)";
                    if (val >= 0) {
                        context.fillText(i, 150, 10 * i + val);
                    } else {
                        context.fillText(i, 150, 10 * i + val);
                    }
                }
            }


            //niewypełniony


        }
        //start rysuj
        rysuj2(0, 0)


        document.getElementById("wsk_skret").addEventListener("mousemove", function () {
            obracaj3(this.getAttribute('value') * Math.PI / 180)
            // console.log(range2.value * Math.PI / 180)
        })

        obracaj3(0)




    }
    init()
}