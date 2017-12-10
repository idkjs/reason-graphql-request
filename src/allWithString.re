
[@bs.module "graphql-request"]
external request : (~x:string, ~y:string) => Js.Promise.t(Js.Json.t) = "request";

let uri = "https://api.graph.cool/simple/v1/cj9o4se940gsu0148s5a4helr";

let query = "
    query allCompanies($filter: String) {
        companies: allCompanies(filter: 
        { name_contains: $filter
        }) {
          id
          name
        }
      }";
  
  request(~x=uri, ~y=query)
  |> Js.Promise.then_(
    data => Js.Promise.resolve(Js.log(data))
  );