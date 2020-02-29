var sciezkaREST = "http://pascal.fis.agh.edu.pl/~7nowaks/TI/ProjektREST";
var logedUser = 0;

function loadBody(){

ifUserLoged();


document.getElementsByClassName("hide_Main")[0].style.display = 'none';
document.getElementsByClassName("hide_Main")[1].style.display = 'none';



}

function insertWeatherValidate(wartosc){
    var form = document.getElementsByTagName("form")[0];
    
    var d1 = new Date(form.data.value+" 00:00:00");
    var d2 = new Date();
    var flag = 1;
   
    if(d2.getTime() < d1.getTime()){
        
        flag = 0;
        alert("Czy jesteś prorokiem?!");
        form.data.focus();
    }
    if(parseInt(form.lowestTemp.value)<-80){
        flag = 0;
        alert("Z tego co wiem temperatura na ziemi, aż tak niska nie jest! :)");
        form.lowestTemp.focus();
    }
    if(parseInt(form.highestTemp.value)>80){
        flag = 0;
        alert("Tak wysokiej temperatury byś nie przeżył gagatku!!! :)");
        form.highestTemp.focus();
    }
    if(parseInt(form.highestTemp.value)<parseInt(form.lowestTemp.value)){
        alert("Najniższa temperatura wyższa od najwyższej? hmmmmmm...");
        flag=0;
    }
	if(!form.data.value ||!form.lowestTemp.value ||!form.highestTemp.value){
		flag =0;
		alert("Uzupełnij dane!");
	}
    if(flag){
        insertWeather(form);
    }

}

function insertWeather(form){
    if(logedUser){
        insertToMongoDB();
    }
    else{       
        insertToLocalDB();
    }
}




function mainPage(){
    document.getElementById("defaultPage").style.display = "block";

document.getElementsByClassName("hide_Main")[0].style.display = 'none';
document.getElementsByClassName("hide_Main")[1].style.display = 'none';
document.getElementById("wynikiOnline").style.display = "none";
}





function addWeather(){
    document.getElementById("defaultPage").style.display = "none";
    document.getElementsByClassName("hide_Main")[0].style.display = 'block';
    document.getElementsByClassName("hide_Main")[1].style.display = 'none';
    document.getElementById("wynikiOnline").style.display = "none";
}



function logIn(){
    document.getElementById("defaultPage").style.display = "none";
    document.getElementsByClassName("hide_Main")[0].style.display = 'none';
    document.getElementsByClassName("hide_Main")[1].style.display = 'block';
    document.getElementById("wynikiOnline").style.display = "none";
    
}



function logOut(){
    setCookie('');
    logedUser=0;
    document.getElementById("log_In").style.display="block";
    document.getElementById("log_Out").style.display="none";
    document.getElementById("resultsData").style.display="none";
    document.getElementById("synchronize").style.display="none";

    
    mainPage();
}
function ifUserLoged(){
    if(LogCookie()){
    logedUser=1;
    mainPage();
    document.getElementById("log_In").style.display="none";
    document.getElementById("log_Out").style.display="block";
    document.getElementById("resultsData").style.display="block";
    document.getElementById("synchronize").style.display="block";
    }

}


function getTempHigh(daneJSON,ilosc_dni){

    const dzien_milisekundy = 1000 * 60 * 60 * 24;
    var av = 0;
    var counter = 0;
    for(x in daneJSON){
        if(parseInt((new Date() - new Date(daneJSON[x].dataPogody))/dzien_milisekundy)==parseInt(ilosc_dni)-1){
            av+=parseInt(daneJSON[x].temperatura_high); 
            counter++;
            
        }
        console.log(parseInt(ilosc_dni));
       
    }
    if(counter>0)
    return parseInt(av/counter);
    else
    return '';
}
function getTempLow(daneJSON,ilosc_dni){

    const dzien_milisekundy = 1000 * 60 * 60 * 24;
    var av = 0;
    var counter = 0;
    for(x in daneJSON){
        if(parseInt((new Date() - new Date(daneJSON[x].dataPogody))/dzien_milisekundy)==parseInt(ilosc_dni)-1){
            av+=parseInt(daneJSON[x].temperatura_low); 
            counter++;
            
        }
        console.log(parseInt(ilosc_dni));
       
    }
    if(counter>0)
    return parseInt(av/counter);
    else
    return '';
}

function showCharts(daneJSON){
    document.getElementById("defaultPage").style.display = "none";
    document.getElementsByClassName("hide_Main")[0].style.display = 'none';
    document.getElementById("wynikiOnline").style.display = "block";
    



    const dzien_milisekundy = 1000 * 60 * 60 * 24;
       
var chart = new CanvasJS.Chart("chartContainer", {
	animationEnabled: true,
	title:{
		text: "Najwyższe średnie temperatury z ostatnich 7 dni"
	},
	axisX: {
		valueFormatString: "DD MMM,YY"
	},
	axisY: {
		title: "Temperatura (w °C)",
		includeZero: false,
		suffix: " °C"
	},
	legend:{
		cursor: "pointer",
		fontSize: 12,
		itemclick: toggleDataSeries
	},
	toolTip:{
		shared: true
	},
	data: [{
		name: "Kraków",
		type: "spline",
		yValueFormatString: "#0.## °C",
		showInLegend: true,
		dataPoints: [
			{ x:  new Date(new Date()-7*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,7) },
			{ x: new Date(new Date()-6*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,6) },
			{ x: new Date(new Date()-5*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,5) },
			{ x: new Date(new Date()-4*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,4) },
			{ x: new Date(new Date()-3*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,3) },
			{ x: new Date(new Date()-2*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,2) },
			{ x: new Date(new Date()-1*dzien_milisekundy), y: getTempHigh(daneJSON.Krakow,1) }
		]
	},
	{
		name: "Katowice",
		type: "spline",
		yValueFormatString: "#0.## °C",
		showInLegend: true,
		dataPoints: [
			{ x:  new Date(new Date()-7*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,7) },
			{ x: new Date(new Date()-6*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,6) },
			{ x: new Date(new Date()-5*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,5) },
			{ x: new Date(new Date()-4*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,4) },
			{ x: new Date(new Date()-3*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,3) },
			{ x: new Date(new Date()-2*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,2) },
			{ x: new Date(new Date()-1*dzien_milisekundy), y: getTempHigh(daneJSON.Katowice,1) }
		]
	},
	{
		name: "Zakopane",
		type: "spline",
		yValueFormatString: "#0.## °C",
		showInLegend: true,
		dataPoints: [
			{ x:  new Date(new Date()-7*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,7) },
			{ x: new Date(new Date()-6*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,6) },
			{ x: new Date(new Date()-5*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,5) },
			{ x: new Date(new Date()-4*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,4) },
			{ x: new Date(new Date()-3*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,3) },
			{ x: new Date(new Date()-2*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,2) },
			{ x: new Date(new Date()-1*dzien_milisekundy), y: getTempHigh(daneJSON.Zakopane,1) }
		]
	}]
});
chart.render();

var chartlow = new CanvasJS.Chart("chartContainerLow", {
	animationEnabled: true,
	title:{
        text: "Najniższe średnie temperatury z ostatnich 7 dni"
       
	},
	axisX: {
		valueFormatString: "DD MMM,YY"
	},
	axisY: {
		title: "Temperatura (w °C)",
		includeZero: false,
		suffix: " °C"
	},
	legend:{
		cursor: "pointer",
		fontSize: 12,
		itemclick: toggleDataSeries
	},
	toolTip:{
		shared: true
	},
	data: [{
		name: "Kraków",
		type: "spline",
		yValueFormatString: "#0.## °C",
		showInLegend: true,
		dataPoints: [
			{ x:  new Date(new Date()-7*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,7) },
			{ x: new Date(new Date()-6*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,6) },
			{ x: new Date(new Date()-5*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,5) },
			{ x: new Date(new Date()-4*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,4) },
			{ x: new Date(new Date()-3*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,3) },
			{ x: new Date(new Date()-2*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,2) },
			{ x: new Date(new Date()-1*dzien_milisekundy), y: getTempLow(daneJSON.Krakow,1) }
		]
	},
	{
		name: "Katowice",
		type: "spline",
		yValueFormatString: "#0.## °C",
		showInLegend: true,
		dataPoints: [
			{ x:  new Date(new Date()-7*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,7) },
			{ x: new Date(new Date()-6*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,6) },
			{ x: new Date(new Date()-5*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,5) },
			{ x: new Date(new Date()-4*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,4) },
			{ x: new Date(new Date()-3*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,3) },
			{ x: new Date(new Date()-2*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,2) },
			{ x: new Date(new Date()-1*dzien_milisekundy), y: getTempLow(daneJSON.Katowice,1) }
		]
	},
	{
		name: "Zakopane",
		type: "spline",
		yValueFormatString: "#0.## °C",
		showInLegend: true,
		dataPoints: [
			{ x:  new Date(new Date()-7*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,7) },
			{ x: new Date(new Date()-6*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,6) },
			{ x: new Date(new Date()-5*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,5) },
			{ x: new Date(new Date()-4*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,4) },
			{ x: new Date(new Date()-3*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,3) },
			{ x: new Date(new Date()-2*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,2) },
			{ x: new Date(new Date()-1*dzien_milisekundy), y: getTempLow(daneJSON.Zakopane,1) }
		]
	}]
});
chartlow.render();



}






function toggleDataSeries(e){
	if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
		e.dataSeries.visible = false;
	}
	else{
		e.dataSeries.visible = true;
	}
	chart.render();
}