package com.dsm.daily_book.entity.Friend;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface FriendRepository extends CrudRepository<Friend, Integer> {
}
