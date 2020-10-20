 
static Card20List
buildCard20List( iRecordStream<char>& iss ){
  Card20List card20List;
  do {
    card20List.emplace_back( iss );
  }
  while( card20List.back().comment.value );
  card20List.pop_back();
  return card20List;
}

