if ( msg.payload.search("MVE") != -1 ) { // Mouvement Entrant
	msg.payload = 2;
	return [null,msg,null,null];
}else if(  msg.payload.search("MVS") != -1  ){ //mouvement Sortant
	msg.payload = 4;
	return [null,null,msg,null];
}else if(  msg.payload.search("TEMP") != -1  ) { // temperature
	var r = /\d+/;
	msg.payload = parseInt(msg.payload.match(r));
	return [msg,null,null,null];
}else { 
	return [null,null,null,msg];
}
