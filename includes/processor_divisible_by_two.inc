<?php

/**
 * @file
 * Custom processor for handling grouping by even and odd.
 */

/**
 * Search API data alteration callback that checks divisble by two.
 */
class SearchApiDivisibleByTwo extends SearchApiAbstractAlterCallback {
  /**
   * Alter the items into there respective groups.
   */
  public function alterItems(array &$items) {
    foreach ($items as $item) {
      if (($item->nid % 2) == 0) {
        $item->divisible = t('Even');
      }
      else {
        $item->divisible = t('Odd');
      }
    }
  }

  /**
   * Processor details.
   */
  public function propertyInfo() {
    return array(
      'divisible' => array(
        'label' => t('Divisible by two'),
        'description' => t('If the node ID is divisble by two.'),
        'type' => 'string',
      ),
    );
  }
}
