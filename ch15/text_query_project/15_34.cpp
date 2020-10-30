/**
 *  @note
 *  for the expression: 
 *      Query q = Query("fiery") & Query("bird") | Query("wind");
 *  (a) List the constructors exexcuted in processing that expression
 *  1: Query::Query(const std::string &s) where s = "fiery", "bird" and "wind"
 *  2. WordQuery::WordQuery(const std::string &s) where s = "fiery", "bird" and "wind"
 *  3. Query operator &
 *     AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
 *  4. BinaryQuery(const Query &l, const Query &r, std::string s)
 *  5. Query::Query(std::shared_ptr<Query_base> query) 2times
 *  6. OrQuery::OrQuery(const Query& left, const Query& right)
 *  7. BinaryQuery(const Query&l, const Query& r, std::string s);
 *  8. Query::Query(std::shared_ptr<Query_base> query) 2times
 */