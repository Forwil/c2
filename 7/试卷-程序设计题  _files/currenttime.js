/****************************************************************
 *   created by zhangjinbo 20070607                             *
 ***************************************************************/
function start_clock(){
   document.all.clock.value = new Date().toString();
   window.setInterval( "document.all.clock.value = new Date().toString()", 1000 );
}
function displayTimebyDate( t )
{
   var date = new Date( t );
   var year = date.getYear()  ;
   var month = date.getMonth() + 1;
   var day = date.getDay();
   var hours = date.getHours();
   var minutes = date.getMinutes();
   var seconds = date.getSeconds();
   if( navigator.appName != "netscape" )
        year += 1900;
   return year + "-" + month + "-" + day + " " + hours + ":" + minutes + ":" + seconds;
}
function clock_start_byDate( $t ){
   timerID = setTimeout( "clock_start(" + ( $t + 1000 ) + ")", 1000 );
   document.all.clock.value = displayTime( $t );
}
function displayTime( t )
{
    t = t % ( 24 * 3600 );
    var hs = t % 3600;
    var hours = ( t - hs ) / 3600;
    hours = ( hours + 8 ) % 24;
    
    var seconds = hs % 60;
    var minutes = ( hs - seconds ) / 60;
    
    if( hours < 10 )
        hours = "0" + hours;
    if( minutes < 10 )
        minutes = "0" + minutes;
    if( seconds < 10 )
        seconds = "0" + seconds;
    return hours + ":" + minutes + ":" + seconds;
}
function clock_start( $t ){
   timerID = setTimeout( "clock_start(" + ( $t + 1 ) + ")", 1000 );
   var o = document.getElementById('clock');
   if (o)
	o.value = displayTime( $t );
}
