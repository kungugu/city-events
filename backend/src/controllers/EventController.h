#pragma once

#include <drogon/HttpController.h>

class EventController : public drogon::HttpController<EventController>
{
    public: 
    METHOD_LIST_BEGIN

    ADD_METHOD_TO(EventController::GetEvents, //список с фильтрами по категории/периоду/«предстоящие» + сортировка
              "/api/events",
              drogon::Get);
    

    ADD_METHOD_TO(EventController::PostEvent, //добавить объявление
              "/api/events",
              drogon::Post);

    ADD_METHOD_TO(EventController::GetEventById, //карточка мероприятия по id
              "/api/events/{1}",
              drogon::Get);

    ADD_METHOD_TO(EventController::EditEventById, //редактировать мероприятие по id
              "/api/events/{1}",
              drogon::Put);             
        
    ADD_METHOD_TO(EventController::RemoveEventById, //удалить мероприятие по id
              "/api/events/{1}",
              drogon::Delete);

    ADD_METHOD_TO(EventController::GetCategories, //список категорий
              "/api/categories",
              drogon::Get);

    

    METHOD_LIST_END
    void GetEvents(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    );

    void PostEvent(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    );

    void GetEventById(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
        int event_id
    );

    void EditEventById(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
        int event_id
    );

    void RemoveEventById(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
        int event_id
    );

    void GetCategories(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    );
    
};